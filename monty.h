#ifndef MONTY_H
#define MONTY_H

/* Includes */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/* Defines */
#define _GNU_SOURCE
#define BUFFER_SIZE 1024

#define PUSH_CODE "push"
#define PALL_CODE "pall"
#define PINT_CODE "pint"
#define POP_CODE "pop"
#define NOP_CODE "nop"
#define SWAP_CODE "swap"
#define ADD_CODE "add"
#define SUB_CODE "sub"
#define DIV_CODE "div"
#define MOD_CODE "mod"
#define MUL_CODE "mul"
#define PCHAR_CODE "pchar"
#define PSTR_CODE "pstr"
#define ROTL_CODE "rotl"
#define ROTR_CODE "rotr"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_func)(stack_t **, unsigned int);


/* GLOBAL VARIABLES */
extern stack_t *head;

FILE *open_file(char *);
void process_file(char *, instruction_t *);
char **parse_line(char *, instruction_t *, int);


/*errors*/
void handle_error(int err_code, ...);
void more_error(int err_code, ...);

/*math operation */
void add_elements (stack_t **, unsigned int);
void subtract_elements (stack_t **, unsigned int);
void multiply_elements (stack_t **, unsigned int);
void divide_elements (stack_t **, unsigned int);
void modulo_elements (stack_t **, unsigned int);
void swap_elements (stack_t **, unsigned int);
void do_nothing (stack_t **, unsigned int);
/*string ASCII */
void printAscii (stack_t **, unsigned int);
void  printStringStack (stack_t **, unsigned int);
/*file*/
void find_fc(char *, char *, int, int);
void call_fc(op_func, char *, char *, int, int);
stack_t *create_N(int num);
void free_stack_nod();
/*open and read */
void open_monty(char *);
/* void readFile(file); */
void pall_stk(stack_t **, unsigned int);
void push_element (stack_t **, unsigned int);
void addto_queue (stack_t **, unsigned int);
void addto_stack (stack_t **, unsigned int);

/*operation sp*/
void pint_elements(stack_t **, unsigned int);
void pop_elements(stack_t **, unsigned int);
void rot_lift(stack_t **, unsigned int);
void rot_right(stack_t **, unsigned int);

/* string utils */
int		_strlen(char *s);
char	*_strdup(char *s);
int		str_numeric(char *str);
#endif /* MONTY_H*/
