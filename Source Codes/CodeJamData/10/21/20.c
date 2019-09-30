#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1003

typedef struct hash {
                char word[200];
                struct hash* next;
        } Hash;

Hash *Word_hash[HASH_SIZE];

int hash_val(char *word)
{
        int str_len;
        int i;
        int hv= 0;

        str_len = strlen(word);
        for (i = 0; i < str_len; i++)
                hv += word[i];
        return hv%HASH_SIZE;
}
int insert_hash(char *word)
{
        int hv, rv = 1;
        Hash *temp, *i_point;

        hv = hash_val(word);
        if (Word_hash[hv] == NULL) {
                Word_hash[hv] = (Hash*)malloc(sizeof(Hash));
                if (Word_hash[hv] == NULL) {
                        perror("");
                        exit(2);
                }
                strcpy(Word_hash[hv]->word, word);
                Word_hash[hv]->next = NULL;
                rv = 1;
        }
        else {
                for (temp = Word_hash[hv]; temp != NULL; i_point = temp, temp = temp->next) {
                        if (!strcmp(temp->word, word)) {
                                rv = 0;
                                break;
                        }
                }
                if (rv) {
                        i_point->next = (Hash*)malloc(sizeof(Hash));
                        if (i_point->next == NULL) {
                                perror("");
                                exit(2);
                        }
                        strcpy((i_point->next)->word, word);
                        (i_point->next)->next = NULL;
                }
        }
        return rv;
}
char* find_hash(char *word)
{
        int hv;
        Hash *temp, *i_point;

        hv = hash_val(word);
        if (Word_hash[hv] == NULL)
                return NULL;
        for (temp = Word_hash[hv]; temp != NULL; i_point = temp, temp = temp->next)
                if (!strcmp(temp->word, word))
                        return temp->word;
        return NULL;

}

int main(int argc, char**argv) {
	FILE *fp_in, *fp_out;
	char tpath[200];
	int count_tc;
	int i,j, k;
	int N, M;
	int no_mkdir;
	if (argc < 3) {
		printf("Usage: %s <input_file> <output_file>\n", argv[0]);
		exit(0);
	}

	fp_in = fopen(argv[1], "r");
	if (fp_in == NULL) {
		perror(argv[1]);
		exit(1);
	}
	fp_out = fopen(argv[2], "w");
	if (fp_out == NULL) {
		perror(argv[2]);
		exit(1);
	}

	fscanf(fp_in, "%d ", &count_tc);
	for (i = 0; i < count_tc; i++) {
		no_mkdir = 0;

		for (j =0; j < HASH_SIZE; j++)
			Word_hash[j] = NULL;
	
		fscanf(fp_in, "%d %d ", &N, &M);
		for (j = 0; j < N; j++) {
			fscanf(fp_in, "%s ", tpath);
			insert_hash(tpath);
		}
		for (j = 0; j < M; j++) {
			fscanf(fp_in, "%s ", tpath);
			if (find_hash(tpath) != NULL)
				continue;
			insert_hash(tpath);
			no_mkdir++;
			for (k = strlen(tpath)-1; k > 0; k--) {
				if (tpath[k] == '/') {
					tpath[k] = '\0';
					if (find_hash(tpath) != NULL) 
						break;
					insert_hash(tpath);
					no_mkdir++;
				}
			}
		}


		fprintf(fp_out, "Case #%d: %d\n", i+1, no_mkdir);
	}


	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
