#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "heap.h"
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
	printf("\nPlease enter your option:\n");
	
	while (TRUE)
	{
		scanf("%c", &opt);
		if ((opt == 'l') || (opt == 's') || (opt == 'a') || (opt == 'g') || (opt == 'r') || (opt == 'p') || (opt == 'e'))
			break;
		else printf("Please enter an available option:\n");
	}
	return opt;
}

void loadTodoList(FILE *list, dynArr *todoHeap)
{	
	printf("in loadTodoList\n");
	Task *tmp = createTask();
	list = fopen(filename, "r+");

	if (list == 0)
	{
		list = fopen(filename, "w+");
	}
	printf("middle loadTodoList\n");
	while (fscanf(list, "%s, %d", tmp->description, &(tmp->priority)) != EOF)
	{
		addDynArr(todoHeap, tmp);
		Task *tmp = createTask();
	}
	printf("end loadTodoList\n");
}

void saveTodoList(FILE *list, dynArr *todoHeap)
{
	if (list == 0)
	{
		printf("The todoList doesn't exist. Please load a todoList first.\n");
		return;
	}

	for (int i = 0; i < sizeDynArr(todoHeap); ++i)
	{
		Task *tmp = getDynArr(todoHeap, i);
		fprintf(list, "%s %d", tmp->description, tmp->priority);
	}
}

void addTodoList(dynArr *todoHeap)
{
	Task *tmp = createTask();
	printf("Please input description:\n");
	scanf("%s", tmp->description);
	printf("Please input priority:\n");
	scanf("%d", &(tmp->priority));
	heapAdd(todoHeap, tmp);
	printf("success\n");

}

void getTodoList(dynArr *todoHeap)
{
	Task *tmp = heapGetFirst(todoHeap);
	printf("%s\n", tmp->description);
}

void removeTodoList(dynArr *todoHeap)
{
	heapRemoveFirst(todoHeap);
}

void printTodoList(dynArr *todoHeap)
{
	for (int i = 0; i < sizeDynArr(todoHeap); ++i)
	{
		Task *tmp = getDynArr(todoHeap, i);
		printf("%s\n", tmp->description);
	}
}

int main(int argc, char *argv[])
{
	FILE *list = 0;
	struct dynArr *todoHeap = createDynArr(10);
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
				saveTodoList(list, todoHeap);
				break;
			case 'a':
				addTodoList(todoHeap);
				break;
			case 'g':
				getTodoList(todoHeap);
				break;
			case 'r':
				removeTodoList(todoHeap);
				break;
			case 'p':
				printTodoList(todoHeap);
				break;
			case 'e':
				exit(0);
		}
	}
	return 0;
}