#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

#define MAX_LINE_SIZE 5000
#define T_MAX 20
#define N_MAX 11


typedef struct node *list;
typedef struct node {
    unsigned long long int quantity;
    unsigned long long int type;
    list next;
};

void print_list(list l)
{
    printf("Quantity : %lu  Type : %lu\n",l->quantity,l->type);
    if(l->next)
        print_list(l->next);
}

void free_list(list l)
{
    if(l->next)
        free_list(l->next);
    free(l);
}


unsigned long long int process(list box, list toy)
{
    unsigned long long int min = 0;
    unsigned long long int a, b;
    list tmp;

    if(!box || !toy)
        return 0;

    if(box->type == toy->type)
    {
        min = MIN(box->quantity,toy->quantity);
        if(box->quantity == toy->quantity)
        {
            return (min + process(box->next,toy->next));
        }
        else if(min == box->quantity)
        {
            tmp = malloc(sizeof(*tmp));
            tmp->quantity = toy->quantity - min;
            tmp->type = toy->type;
            tmp->next = toy->next;
            a = process(box->next,tmp);
            free(tmp);
            return (min + a);
        }
        else
        {
            tmp = malloc(sizeof(*tmp));
            tmp->quantity = box->quantity - min;
            tmp->type = box->type;
            tmp->next = box->next;
            a = process(tmp,toy->next);
            free(tmp);
            return (min + a);
        }
    }
    else
    {
        a = process(box, toy->next);
        b = process(box->next, toy);
        return (MAX(a,b));

    }
}

int main(int argc, char *argv[])
{
    /* variables communes*/
    unsigned long long int T, N, M, i, j;
    FILE *fp, *fo;
    char buff[MAX_LINE_SIZE];
    char *splitLine = NULL;
    /* fin des variables communes*/

    list box, tmp_box, prev_box;
    list toy, tmp_toy, prev_toy;
    /* code commun*/
    if(argc > 1)
    {
        fp = fopen(argv[1], "r");
        fo = fopen("output", "w");
        if(!fp || !fo)
        {
            printf("Can't read the file.");
            exit (EXIT_FAILURE);
        }
        fgets(buff, MAX_LINE_SIZE, fp);
        T = atoi(buff);
        for(i = 0; i < T; i++)
        {
            fgets(buff, MAX_LINE_SIZE, fp);
            splitLine = strtok(buff," ");
            N = strtoul(splitLine, NULL, 10);
            splitLine = strtok(NULL," ");
            M = strtoul(splitLine, NULL, 10);
    /* fin du code commun*/

            /*contruction de la liste des box*/
            fgets(buff, MAX_LINE_SIZE, fp);
            splitLine = strtok(buff," ");
            box = malloc(sizeof(*box));
            box->quantity = strtoul(splitLine, NULL, 10);
            splitLine = strtok(NULL," ");
            box->type = strtoul(splitLine, NULL, 10);
            box->next = NULL;
            prev_box = box;
            for(j = 1; j < N; j++)
            {
                tmp_box = malloc(sizeof(*tmp_box));
                prev_box->next = tmp_box;
                splitLine = strtok(NULL," ");
                tmp_box->quantity = strtoul(splitLine, NULL, 10);
                splitLine = strtok(NULL," ");
                tmp_box->type = strtoul(splitLine, NULL, 10);
                tmp_box->next = NULL;
                prev_box = tmp_box;
            }
            /*construction de la liste des toy*/
            fgets(buff, MAX_LINE_SIZE, fp);
            splitLine = strtok(buff," ");
            toy = malloc(sizeof(*toy));
            toy->quantity = strtoul(splitLine, NULL, 10);
            splitLine = strtok(NULL," ");
            toy->type = strtoul(splitLine, NULL, 10);
            toy->next = NULL;
            prev_toy = toy;
            for(j = 1; j < M; j++)
            {
                tmp_toy = malloc(sizeof(*tmp_toy));
                prev_toy->next = tmp_toy;
                splitLine = strtok(NULL," ");
                tmp_toy->quantity = strtoul(splitLine, NULL, 10);
                splitLine = strtok(NULL," ");
                tmp_toy->type = strtoul(splitLine, NULL, 10);
                tmp_toy->next = NULL;
                prev_toy = tmp_toy;
            }
            /*
            printf("BOX\n");
            print_list(box);
            printf("TOY\n");
            print_list(toy);*/
            //printf("%lu\n", process(box,toy));
            fprintf(fo,"Case #%lu: %lu\n",i+1,process(box,toy));
            free_list(box);
            free_list(toy);
        }
        fclose(fp);
        fclose(fo);
        exit (EXIT_SUCCESS);
    }
    exit (EXIT_SUCCESS);
}
