#include "Ball.h"

Vector2 Ball::CalculateCollision(GameObject* other)
{
    int vertical = 0;
    int horizontal = 0;

    for (int i = 0; i < objects.size(); i++) {
        bool top = (other->GetPosition() + Vector2(0, -1)) == objects[i]->GetPosition();
        bool bottom = (other->GetPosition() + Vector2(0, 1)) == objects[i]->GetPosition();
        vertical += (int)top + (int)bottom;

        bool left = (other->GetPosition() + Vector2(-1, 0)) == objects[i]->GetPosition();
        bool right = (other->GetPosition() + Vector2(1, 0)) == objects[i]->GetPosition();
        horizontal += (int)left + (int)right;
    }

    Vector2 outDir = direction;

    if (vertical == 0 && horizontal == 0) {
        vertical = rand() % 2;
        horizontal = rand() % 2;
        if (vertical == 0 && horizontal == 0) vertical = 1;
    }

    if (vertical >= horizontal)
        outDir.x = -outDir.x;
    if (horizontal > vertical)
        outDir.y = -outDir.y;

    return outDir;
}


void Ball::Update()
{
    Vector2 nextPos = position + direction;
    bool collision = false;
    bool outOfBounds = false;

    for (GameObject* go : objects) {
        if (go == this) continue;

        // Colisi�n con paredes
        if (nextPos == go->GetPosition()) {
            if (Wall* w = dynamic_cast<Wall*>(go)) {
                // Verificar si es el muro inferior (#)
                if (go->GetPosition().y > position.y && go->GetPosition().y < 2) { // Colisi�n por abajo
                    outOfBounds = true;
                    break;
                }
                // Para todas las dem�s paredes (laterales y superior), solo rebotar
                else {
                    outOfBounds = false; // No se sale de los l�mites
                    // Determinar si la colisi�n es principalmente horizontal o vertical
                    int verify = go->GetPosition().y;
                    bool isHorizontalCollision = (nextPos.x != position.x); // Colisi�n con pared lateral
                    if (nextPos.y == 0) {
                        direction.y = -direction.y; // Rebote vertical (techo)
                    }
                    else if (isHorizontalCollision) {
                        direction.x = -direction.x; // Rebote horizontal
                    }
                    else {
                        if (nextPos.y < position.y) {
                            direction.y = -direction.y; // Rebote vertical (techo)
                        }
                        else if (nextPos.y > position.y) {
                            direction.y = -direction.y; // Rebote vertical (suelo)
                        }
                        else if (nextPos.y == 0) {
                            direction.y = -direction.y;
                        }
                    }
                    if (nextPos.y == 14) {
                        outOfBounds = true;
                    }
                    collision = true;
                    break;
                }
            }
        }

        // Colisi�n con ladrillos ("=")
        if (nextPos == go->GetPosition()) {
            if (Brick* b = dynamic_cast<Brick*>(go)) {
                // Destruir el ladrillo
                b->Destroy();

                // Determinar direcci�n de rebote
                Vector2 brickPos = b->GetPosition();

                // Rebote vertical si golpeamos desde arriba/abajo
                if (position.y != brickPos.y) {
                    direction.y = -direction.y;
                }
                // Rebote horizontal si golpeamos de lado
                else {
                    direction.x = -direction.x;
                }
                gameManager.AddPoints();
                collision = true;
                for (auto it = objects.begin(); it != objects.end(); ++it) {
                    if (*it == go) {
                        objects.erase(it);
                        break;
                    }
                }
                break;
            }
        }

        // Colisi�n con el Pad (versi�n funcional)
        if (Pad* p = dynamic_cast<Pad*>(go)) {
            Vector2 padPos = p->GetPosition();
            int padWidth = p->GetWidth();
            gameManager.ResetMultiplier();


            if (nextPos.y == padPos.y &&
                nextPos.x >= padPos.x - padWidth &&
                nextPos.x <= padPos.x + padWidth) {

                // Rebote b�sico pero funcional
                direction.y = -1; // Siempre hacia arriba

                // Ajuste simple de direcci�n X
                if (nextPos.x < padPos.x) { // Golpe izquierda
                    direction.x = -1;
                }
                else if (nextPos.x > padPos.x) { // Golpe derecha
                    direction.x = 1;
                }
                else { // Golpe centro
                    direction.x = 0;
                }

                // Mover la pelota fuera del �rea de colisi�n
                position.y = padPos.y - 1;
                position.x = nextPos.x;

                collision = true;
                break;
            }
        }
    }

    if (outOfBounds) {
        gameManager.Attempts();
        // Reiniciar posici�n de la pelota
        position = Vector2(7, 7); // Posici�n inicial
        direction = Vector2(rand() % 3 - 1, 1);
        // Aqu� podr�as restar una vida si implementas un sistema de vidas
    }
    else if (!collision) {
        position = nextPos;
    }
}