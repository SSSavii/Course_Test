#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct security
{
    char code[31];
    int id;
    int reliability;
};

struct security* securities;
int num_securities = 0;

struct response
{
    char message[100];
};

struct response* responses;
int num_responses = 0;

void issue_security(char* code)
{
    for (int i = 0; i < num_securities; i++)
    {
        if (strcmp(securities[i].code, code) == 0)
        {
            if (securities[i].id == -1)
            {
                securities[i].id = num_securities;
                securities[i].reliability = 0;
                sprintf(responses[num_responses].message, "OK %s %d %d\n", code, securities[i].id, securities[i].reliability);
                num_responses++;
            }
            else
            {
                struct security new_security;
                strcpy(new_security.code, code);
                new_security.id = num_securities;
                new_security.reliability = 0;
                securities = (struct security*)realloc(securities, (num_securities + 1) * sizeof(struct security));
                securities[num_securities] = new_security;
                sprintf(responses[num_responses].message, "CREATED %d %d\n", securities[num_securities].id, securities[num_securities].reliability);
                num_responses++;
                num_securities++;
            }
            return;
        }
    }

    struct security new_security;
    strcpy(new_security.code, code);
    new_security.id = num_securities;
    new_security.reliability = 0;
    securities = (struct security*)realloc(securities, (num_securities + 1) * sizeof(struct security));
    securities[num_securities] = new_security;
    sprintf(responses[num_responses].message, "CREATED %d %d\n", securities[num_securities].id, securities[num_securities].reliability);
    num_responses++;
    num_securities++;
}

void delete_security(char* code)
{
    for (int i = 0; i < num_securities; i++)
    {
        if (strcmp(securities[i].code, code) == 0)
        {
            if (securities[i].id == -1)
            {
                strcpy(responses[num_responses].message, "BAD REQUEST\n");
                num_responses++;
            }
            else
            {
                sprintf(responses[num_responses].message, "OK %d %d\n", securities[i].id, securities[i].reliability);
                securities[i].id = -1;
                securities[i].reliability = -10000000;
                num_responses++;
            }
            return;
        }
    }

    strcpy(responses[num_responses].message, "BAD REQUEST\n");
    num_responses++;
}

void change_reliability(char* code, int reliability)
{
    for (int i = 0; i < num_securities; i++)
    {
        if (strcmp(securities[i].code, code) == 0)
        {
            if (securities[i].id == -1)
            {
                strcpy(responses[num_responses].message, "BAD REQUEST\n");
                num_responses++;
            }
            else
            {
                securities[i].reliability += reliability;
                sprintf(responses[num_responses].message, "OK %d %d\n", securities[i].id, securities[i].reliability);
                num_responses++;
            }
            return;
        }
    }

    strcpy(responses[num_responses].message, "BAD REQUEST\n");
    num_responses++;
}

int compare_securities(const void* a, const void* b)
{
    struct security* security_a = (struct security*)a;
    struct security* security_b = (struct security*)b;

    if (security_a->reliability != security_b->reliability)
    {
        return security_b->reliability - security_a->reliability;
    }
    else
    {
        return security_a->id - security_b->id;
    }
}

void find_security(int n)
{
    if (num_securities == 0)
    {
        strcpy(responses[num_responses].message, "EMPTY\n");
        num_responses++;
        return;
    }

    if (n >= num_securities)
    {
        n = num_securities - 1;
    }

    struct security* sorted_securities = (struct security*)malloc(num_securities * sizeof(struct security));
    memcpy(sorted_securities, securities, num_securities * sizeof(struct security));

    qsort(sorted_securities,
        num_securities, sizeof(struct security), compare_securities);

    sprintf(responses[num_responses].message, "OK %s %d %d\n", sorted_securities[n].code, sorted_securities[n].id, sorted_securities[n].reliability);
    num_responses++;

    free(sorted_securities);
}

int main()
{
    int num_queries;
    scanf("%d", &num_queries);

    securities = (struct security*)malloc((num_queries + 1) * sizeof(struct security));
    responses = (struct response*)malloc((num_queries + 1) * sizeof(struct response));

    for (int i = 0; i < num_queries; i++)
    {
        char query_type[12];
        char code[31];
        int reliability;
        int n;

        scanf("%s", query_type);

        if (strcmp(query_type, "ISSUE") == 0)
        {
            scanf("%s", code);
            issue_security(code);
        }
        else if (strcmp(query_type, "DELETE") == 0)
        {
            scanf("%s", code);
            delete_security(code);
        }
        else if (strcmp(query_type, "RELIABILITY") == 0)
        {
            scanf("%s %d", code, &reliability);
            change_reliability(code, reliability);
        }
        else if (strcmp(query_type, "FIND") == 0)
        {
            scanf("%d", &n);
            find_security(n);
        }
    }

    for (int i = 0; i < num_responses; i++)
    {
        printf("%s", responses[i].message);
    }

    free(securities);
    free(responses);

    return 0;
}