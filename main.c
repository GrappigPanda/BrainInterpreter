#include <stdio.h>
#include <string.h>
#include "LinkedList.c"

int find_last_loop(char *commands, int count)
{
        while(count != 0) {
                if(commands[count] == '[') {
                        return count;
                }
        --count;
        }
        return -1;
}

void parse_commands(struct Node *data_list, char *commands,
                    int count, int where)
{
        switch(commands[count]) {
        case '+':
                data_list->value += 1;
                break;
        case '-':
                data_list->value -= 1;
                break;
        case '>': {
                if(data_list->next == NULL) {
                        struct Node *new = create(0);
                        data_list = append(data_list, new);
                } else {
                        data_list = data_list->next;
                }
                break;
        }
        case '<': {
                if(data_list->prev == NULL) {
                        struct Node *new = create(0);
                        data_list = prepend(data_list, new);
                } else {
                        data_list = data_list->prev;
                }
                break;
        }
        case ',':
                data_list->value = getchar();
                break;
        case '.':
                putchar(data_list->value);
                break;
        case '[':
                break;
        case ']': {
                if(!(data_list->value == 0)) {
                        if(where == -1) {
                                where = find_last_loop(commands, count);
                                if(where == -1)
                                        return;
                                else
                                        parse_commands(data_list, commands,
                                                       where, where);
                        } else {
                                parse_commands(data_list, commands,
                                               where, where);
                        }
                } else {
                        parse_commands(data_list, commands, ++count, where);
                }
        }
        default:
                return;
        }
        
        if(strlen(commands) == count) {
                return;
        } else {
                parse_commands(data_list, commands, ++count, where);
        }
}

int parse_commands_list(struct Node* data_list, char *commands)
{
    int command_len = strlen(commands);

    if(!(command_len > 0))
        return -1;

    parse_commands(data_list, commands, 0, -1);

    return 0;
}

int main()
{
    struct Node *fst = create(0);
    parse_commands_list(fst, "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    free_all_registers(fst);
    return 0;
}
