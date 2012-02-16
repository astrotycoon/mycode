/***************************************************************************
*	编程判断一个字符串是否是回文。
*
*	思路: 利用栈的“先进后出”，队列的“先进先出”特性分别将字符串入栈、入
*	队列，最后同时出栈和出队列，分别比较，若相等则为回文，反之不然。
*
*	其实这样的思路并不好，只是验证自己写的栈与队列。
*
*	时间: 22时06分46秒
*	
*	作者: astrol
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "stack.h"
#include "queue.h"

void err_exit(char *str_err);
void stack_push_string(p_stack_t stack, char *string);
void queue_push_string(p_queue_t queue, char *string);
int compare(p_stack_t stack, p_queue_t queue);
void print(void *data);
bool stack_delete_base(p_stack_t stack);

int main(int argc, char *argv[])
{
	p_stack_t stack = NULL;
	p_queue_t queue = NULL;
	char buffer[1024] = {0};

	/* initional the stack and queue */
	stack = stack_create();
	queue = queue_create();
	if (stack == NULL || queue == NULL)
	{
		err_exit("create error");
	}

	printf("Please input a string!\n");
	while (fgets(buffer, 1024, stdin))
	{
		stack_push_string(stack, buffer);
		queue_push_string(queue, buffer);
		printf("---%c---\n", *(char *)queue_gethead(queue));
		printf("---%c---\n", *(char *)get_top(stack));
		queue_print(queue, print);
		stack_print(stack, print);

		if (compare(stack, queue) == 1)
		{
			printf("回文!\n");
		} 
		else
		{
			printf("不是回文!\n");
		}

	}
	
	printf("Done!\n");
	return 0;
}

void err_exit(char *str_err)
{
	perror(str_err);
	exit(EXIT_FAILURE);
}

void stack_push_string(p_stack_t stack, char *string)
{
	while (*string)
	{
		stack_push(stack, string);
		string++;
	}

}

void queue_push_string(p_queue_t queue, char *string)
{
	while (*string)
	{
		queue_put(queue, string);
		string++;
	}

}

int compare(p_stack_t stack, p_queue_t queue)
{
	p_slnode_t base = stack->base;
	while (stack->size)
	{
		p_slnode_t base = stack->base;
		if (*(char *)queue_gethead(queue) 
		!= *(char *)base->data)
		{
			return 0;
		}	
		stack_delete_base(stack);
		queue_delete(queue);
	}

	return 1;
}

void print(void *data)
{
	printf("%c ", *(char *)data);
}

bool stack_delete_base(p_stack_t stack)
{
	if (NULL == stack)
	{
		errno = EINVAL;
		return false;
	}

	p_slnode_t second = stack->top;
	while (second != stack->base)
	{
		second = second->next;
	}
	
//	free(stack->base->data);
	free(stack->base);
	stack->base = second;
	stack->base->next = NULL;
	stack->size--;
	
	return true;
}
