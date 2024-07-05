/*
 * Copyright (c) 2024, Patrick Wilmes <p.wilmes89@gmail.com>
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    void *data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *node_new(void *data){
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void node_append(Node **head, void *data) {
    Node *new_node = node_new(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void print_int_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d\n", *(int *) temp->data);
        temp = temp->next;
    }
}

void node_free(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *temp;
    Node *list = head;
    while (list != NULL) {
        temp = list;
        list = temp->next;
        free(temp);
    }
}

int main(int argc, char **argv) {
    Node *int_list = NULL;

    int number1 = 1;
    int number2 = 2;
    int number3 = 3;

    node_append(&int_list, &number1);
    node_append(&int_list, &number2);
    node_append(&int_list, &number3);

    print_int_list(int_list);

    node_free(int_list);
    return 0;
}
