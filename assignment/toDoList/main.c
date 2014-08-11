#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "todoList.h"
#include "dynArr.h"
#include "type.h"

#define TRUE 1

Task *createTask()
{
	Task *newTask = malloc(sizeof(Task));
	assert(newTask != 0);
	newTask->priority = 0;
	return newTask;
}

char const options[] = "'l': load todoList from file\n"
				"'s': save todoList to file\n"
				"'a': add a new task to the todoList\n"
				"'g': get the first task from the todoList\n"
				"'r': remove the first task from the todoList\n"
				"'p': print th todoList\n"
				"'e': exit the program\n";

char const filename[] = "todo.list";

char getOption()
{	
	char opt;
	printf("%sPlease enter your option\n", options);
	while (TRUE)
	{
		scanf(%c, &opt);
		if ((opt == 'l') || (opt == 's') || (opt == 'a') || (opt == 'g') || (opt == 'r') || (opt == 'p') || (opt == 'e'))
			break;
		else printf("Please enter an available option:\n");
	}
	return opt;
}

void loadTodoList(FILE *list, dynArr *todoHeap)
{	
	Task *tmp = createTask();
	list = fopen(filename, 'r+');

	if (list == 0)
	{
		list = fopen(filename, 'w');
	}

	while (fscanf(list, "%s, %d", tmp->description, &(tmp->priority)) != EOF)
	{
		addDynArr(todoHeap, tmp);
		Task *tmp = createTask();
	}
}

void saveTodoList(FILE *list)
{
	if (list == 0)
	{
		/* code */
	}
}

int main(int argc, char *argv[])
{
	FILE *list;
	dynArr *todoHeap = createDynArr(10);
	char option;

	while (TRUE)
	{
		option = getOption();

		switch (option)
		{
			case 'l':
				loadTodoList(list, todoHeap);
				break;
			case 's':
				saveTodoList(list);
				break;
			case 'a':
				addTodoList(list);
				break;
			case 'g':
				getTodoList(list);
				break;
			case 'r':
				removeTodoList(list);
				break;
			case 'p':
				printTodoList(list);
				break;
			case 'e':
				exit(0);
		}
	}
	return 0;
}