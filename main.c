#include <stdio.h>
#include <string.h>
#include "LinkedList.c"

int findwherelastloop(char *commands, int count) {
    while(count != 0) {
    if(commands[count] == '[') {
        return count;
    }
    --count;
    }
    return -1;
}

void parse_commands(struct Node* DataList, char *commands, int count, int where) {
    switch(commands[count]) {
        case '+':
            DataList->value += 1;
            break;
        case '-':
            DataList->value -= 1;
            break;
        case '>': {
            if(DataList->next == NULL) {
                struct Node* new = create(0);
                DataList = append(DataList, new);
            } else
                DataList = DataList->next;
            break;
        }
        case '<': {
            if(DataList->prev == NULL) {
                struct Node* new = create(0);
                DataList = prepend(DataList, new);
            } else
            DataList = DataList->prev;
            break;
        }
        case ',':
            DataList->value = getchar();
            break;
        case '.':
            putchar(DataList->value);
            break;
        case '[':
            break;
        case ']': {
            if(!(DataList->value == 0)) {
                if(where == -1) {
                    where = findwherelastloop(commands, count);
                    if(where == -1)
                        return;
                    else
                        parse_commands(DataList, commands, where, where);
                } else
                    parse_commands(DataList, commands, where, where);
            } else
                parse_commands(DataList, commands, ++count, where);
        }
        default:
            return;
    }
    if(strlen(commands) == count) {
        return;
    }
    else
        parse_commands(DataList, commands, ++count, where);
}

int parse_commands_list(struct Node* DataList, char *commands) {
    int command_len = strlen(commands);

    if(!(command_len > 0))
        return -1;

    parse_commands(DataList, commands, 0, -1);

    return 0;
}

int main() {
    struct Node* fst = create(0);
    parse_commands_list(fst, "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");
    free_all_registers(fst);
    return 0;
}
