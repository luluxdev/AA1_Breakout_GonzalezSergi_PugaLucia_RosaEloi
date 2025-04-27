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

        // Colisión con paredes
        if (nextPos == go->GetPosition()) {
            if (Wall* w = dynamic_cast<Wall*>(go)) {
                // Verificar si es el muro inferior (#)
                if (go->GetPosition().y > position.y) { // Colisión por abajo
                    outOfBounds = true;
                    break;
                }
                // Rebote normal en otras paredes
                direction.x = -direction.x;
                collision = true;
                break;
            }
        }

        // Colisión con ladrillos ("=")
        if (nextPos == go->GetPosition()) {
            if (Brick* b = dynamic_cast<Brick*>(go)) {
                // Destruir el ladrillo
                b->Destroy();

                // Determinar dirección de rebote
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
                break;
            }
        }

        // Colisión con el Pad (versión funcional)
        if (Pad* p = dynamic_cast<Pad*>(go)) {
            Vector2 padPos = p->GetPosition();
            int padWidth = p->GetWidth();

            if (nextPos.y == padPos.y &&
                nextPos.x >= padPos.x - padWidth &&
                nextPos.x <= padPos.x + padWidth) {

                // Rebote básico pero funcional
                direction.y = -1; // Siempre hacia arriba

                // Ajuste simple de dirección X
                if (nextPos.x < padPos.x) { // Golpe izquierda
                    direction.x = -1;
                }
                else if (nextPos.x > padPos.x) { // Golpe derecha
                    direction.x = 1;
                }
                else { // Golpe centro
                    direction.x = (rand() % 2) ? 1 : -1;
                }

                // Mover la pelota fuera del área de colisión
                position.y = padPos.y - 1;
                position.x = nextPos.x;

                collision = true;
                break;
            }
        }
    }

    if (outOfBounds) {
        // Reiniciar posición de la pelota
        position = Vector2(5, 5); // Posición inicial
        direction = Vector2(1, 1); // Dirección inicial
        // Aquí podrías restar una vida si implementas un sistema de vidas
    }
    else if (!collision) {
        position = nextPos;
    }
}