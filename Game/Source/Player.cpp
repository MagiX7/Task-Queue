#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Render.h"

#include "Player.h"
#include "TaskManager.h"

#include "Log.h"

#define SPEED_X 100.0f
#define SPEED_Y 100.0f

Player::Player(EntityType type, iPoint pos) : Entity(type)
{
	name.Create("player");

	bounds.x = pos.x;
	bounds.y = pos.y;

	pugi::xml_parse_result result = pushbacksFile.load_file("pushbacks.xml");

	if (result == NULL)
	{
		LOG("Could not load the file, pugi error: ", result.description());
	}
	else
	{
		pushbacksNode = pushbacksFile.child("pushbacks");
		playerNode = pushbacksNode.child("player");

		// Load pushbacks animations for each animation
		pugi::xml_node n;

		for (n = playerNode.child("idle_animation").child("pushback"); n; n = n.next_sibling("pushback"))
		{
			idleAnim.PushBack({ n.attribute("x").as_int(), n.attribute("y").as_int(), n.attribute("w").as_int(), n.attribute("h").as_int() });
		}

		for (n = playerNode.child("walk_left_animation").child("pushback"); n; n = n.next_sibling("pushback"))
		{
			walkLeftAnim.PushBack({ n.attribute("x").as_int(), n.attribute("y").as_int(), n.attribute("w").as_int(), n.attribute("h").as_int() });
		}

		for (n = playerNode.child("walk_right_animation").child("pushback"); n; n = n.next_sibling("pushback"))
		{
			walkRightAnim.PushBack({ n.attribute("x").as_int(), n.attribute("y").as_int(), n.attribute("w").as_int(), n.attribute("h").as_int() });
		}
	}

}

bool Player::Load()
{
	moveLeft = new MoveLeft(this);
	moveRight = new MoveRight(this);
	moveUp = new MoveUp(this);
	moveDown = new MoveDown(this);

	texture = app->tex->Load("Assets/Textures/Player/player.png");
	currentAnim = &idleAnim;

	// 0 right, 1 left
	direction = 0;

	return true;
}

bool Player::Update(float dt)
{
	bool ret = true;

	idleAnim.speed = 5.0f * dt;
	walkLeftAnim.speed = 7.0f * dt;
	walkRightAnim.speed = 7.0f * dt;

	ret = HandleInput(dt);

	LOG("PLAYER POS: %i %i", bounds.x, bounds.y);

	currentAnim->Update();

	return ret;
}

void Player::Draw()
{
	app->render->DrawTexture(texture, bounds.x, bounds.y, &currentAnim->GetCurrentFrame());
}

bool Player::UnLoad()
{
	app->tex->UnLoad(texture);

	RELEASE(moveLeft);
	RELEASE(moveRight);
	RELEASE(moveUp);
	RELEASE(moveDown);

	return true;
}

bool Player::HandleInput(float dt)
{
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		if (direction == 0)
		{
			currentAnim = &walkRightAnim;
		}
		else if (direction == 1)
		{
			currentAnim = &walkLeftAnim;
		}
		app->taskManager->EnqueueTask(moveUp);
		//moveUp->Execute(dt, this);
		//bounds.y -= 50 * dt;
	}

	if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		if (direction == 0)
		{
			currentAnim = &walkRightAnim;
		}
		else if (direction == 1)
		{
			currentAnim = &walkLeftAnim;
		}
		app->taskManager->EnqueueTask(moveDown);
		//moveDown->Execute(dt, this);
		//bounds.y += 350 * dt;
	}

	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		direction = 1;

		if (currentAnim != &walkLeftAnim)
		{
			walkLeftAnim.Reset();
			currentAnim = &walkLeftAnim;
		}
		app->taskManager->EnqueueTask(moveLeft);
		//moveLeft->Execute(dt, this);
		//bounds.x -= 50 * dt;
	}

	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		direction = 0;

		if (currentAnim != &walkRightAnim)
		{
			walkRightAnim.Reset();
			currentAnim = &walkRightAnim;
		}
		app->taskManager->EnqueueTask(moveRight);
		//moveRight->Execute(dt, this);
		//bounds.x += 350 * dt;
	}

	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE &&
		app->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE &&
		app->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE &&
		app->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE)
	{
		currentAnim = &idleAnim;
	}


	return true;
}