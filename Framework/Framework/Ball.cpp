#include "Ball.h"
#include "defines.h"

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
		// If both are 0, we need to set one of them to 1 to avoid division by zero:
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

        // 1. Wall's collision:
        if (nextPos == go->GetPosition()) {
            if (Wall* w = dynamic_cast<Wall*>(go)) {

				// Chek if the wall is a bottom wall:
                if (go->GetPosition().y > position.y && go->GetPosition().y < 2) {
                    outOfBounds = true;
                    break;
                }

				// For the other walls:
                else {
                    outOfBounds = false;

					// Check if the wall is a vertical wall:
                    int verify = go->GetPosition().y;
                    bool isHorizontalCollision = (nextPos.x != position.x);

					// Vertical collision:
                    if (nextPos.y == TOP) {
                        direction.y = -direction.y;
                    }
                    // Horizontal collision:
                    else if (isHorizontalCollision) {
                        direction.x = -direction.x;
                    }
                    else {
                        // Top collision:
                        if (nextPos.y < position.y) {
                            direction.y = -direction.y;
                        }
                        // Bottom collision:
                        else if (nextPos.y > position.y) {
                            direction.y = -direction.y;
                        }
                        else if (nextPos.y == TOP) {
                            direction.y = -direction.y;
                        }
                    }
                    if (nextPos.y == BOTTOM) {
                        outOfBounds = true;
                    }
                    collision = true;
                    break;
                }
            }
        }

		// 2. Brick's collision:
        if (nextPos == go->GetPosition()) {
            if (Brick* b = dynamic_cast<Brick*>(go)) {
				// Destroy the brick:
                b->Destroy();

				// Define bounce direction:
                Vector2 brickPos = b->GetPosition();

                // Vertical bounce:
                if (position.y != brickPos.y) {
                    direction.y = -direction.y;
                }
                // Horizontal bounce:
                else {
                    direction.x = -direction.x;
                }

				// Add points to the player:
                gameManager.AddPoints();
                collision = true;

				// Remove the brick from the list of objects: (REF.: CHAT GPT)
                for (auto it = objects.begin(); it != objects.end(); ++it) {
                    if (*it == go) {
                        objects.erase(it);
                        break;
                    }
                }
                break;
            }
        }

		// 3. Pad's collision:
        if (Pad* p = dynamic_cast<Pad*>(go)) {

            Vector2 padPos = p->GetPosition();
            int padWidth = p->GetWidth();

			// Reset multiplier if the ball is in the pad's area:
            gameManager.ResetMultiplier();

			// Check if the ball is within the pad's width:
            if (nextPos.y == padPos.y &&
                nextPos.x >= padPos.x - padWidth &&
                nextPos.x <= padPos.x + padWidth) {

                direction.y = -1;

				// Left side hit:
                if (nextPos.x < padPos.x) {
                    direction.x = -1;
                }
                // Right side hit:
                else if (nextPos.x > padPos.x) {
                    direction.x = 1;
                }
                // Center hit:
                else {
                    direction.x = 0;
                }

				// Move the ball to the pad's position:
                position.y = padPos.y - 1;
                position.x = nextPos.x;

                collision = true;
                break;
            }
        }
    }

    if (outOfBounds) {

		// Add a life lost:
        gameManager.Attempts();

		// Initialize the ball's position:
        position = Vector2(CENTER, CENTER);
		// And the direction (rand between -1 and 1):
        direction = Vector2(rand() % 3 - 1, 1);

    }
    else if (!collision) {
		// Move the ball:
        position = nextPos;
    }
}