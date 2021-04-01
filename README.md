# Task Queue

## Introduction
My name is David González and I am a videogame developer student at CITM.

This is a personal research for CITM (UPC) about task queues in videogames and how to implement one.


## About Task Queues
There are two types of task queues: Push and Pull Queues.
- Push Queues are those that execute the task automatically.
- Pull Queues, on the other hand, are those that have a list of actions and you can execute whenever you want.

## Task Queues in RPG videogames
In the combat of Pokémon Colosseum we can see an example of a task queue. First, the player chooses the actions for each pokémon and later they are executed.

In Warcraft 3 Reforged, when a pawn is doing a task and you assign another task to him, he first finishes the current task he is doing before starting the next one.

## Pattern
The most common pattern to do a task list is the Command pattern, which consists in a method call wrapped in an object.

If you want to see more, go and check the webpage [HERE](magix7.github.io/task-queue/).
