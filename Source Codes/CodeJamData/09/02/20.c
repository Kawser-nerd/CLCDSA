#include <stdio.h>

#define FILE_NAME	"test.in"

struct cell {
	int altitude;
	int prev_row[4];
	int prev_column[4];
	int prev_count;
	int have_next;
	char label;
};

struct queue {
	struct cell *cells[10000];
	int min;
	int count;
};

int compare(const void *p, const void *q)
{
	if (((struct queue *)p)->min < ((struct queue*)q)->min) {
		return -1;
	} else {
		return 1;
	}
}

main()
{
	FILE *fp = NULL;
	char line[1000000];
	char *data = NULL;
	char *number = NULL;
	struct cell cells[100][100];
	int i = 0, j = 0, k = 0, l = 0;
	int t = 0, h = 0, w = 0;
	int count = 0;
	int min_altitude = 0;
	int next_row = -1;
	int next_column = -1;
	struct queue cell_queue[26];
	int cell_queue_start = 0;
	int cell_queue_end = 0;
	int queue_index = 0;
	int column = 0, row = 0;

	fp = fopen(FILE_NAME, "r");
	if (!fp) {
		goto err;
	}

	if (fgets(line, sizeof(line), fp)) {
		sscanf(line, "%d", &t);
	} else {
		goto err;
	}

	if (t < 0 || t > 100) {
		goto err;
	}

	for (i = 0; i < t; i++) {
		if (fgets(line, sizeof(line), fp)) {
			sscanf(line, "%d %d", &h, &w);
			if (h < 1 || h > 100 || w < 1 || w > 100) {
				goto err;
			}
		} else {
			goto err;
		}

		for (j = 0; j < h; j++) {
			if (fgets(line, sizeof(line), fp)) {
				for (number = line, data = line, k = 0; '\0' != *data; data++) {
					if (' ' == *data || '\r' == *data 
						|| '\n' == *data || '\t' == *data) {
						*data = '\0';
						cells[j][k].altitude = atoi(number);
						cells[j][k].prev_count = 0;
						cells[j][k].have_next = 0;
						k++;
						if (k >= w) {
							break;
						}
						number = data + 1;
					}
				}
			} else {
				goto err;
			}
		}


		for (j = 0; j < h; j++) {
			for (k = 0; k < w; k++) {
				min_altitude = cells[j][k].altitude;
				next_row = -1;
				next_column = -1;

				//north
				if (j > 0) {
					if (cells[j - 1][k].altitude < min_altitude) {
						next_row = j - 1;
						next_column = k;
						min_altitude = cells[j - 1][k].altitude;
					}
				}

				//west
				if (k > 0) {
					if (cells[j][k - 1].altitude < min_altitude) {
						next_row = j;
						next_column = k - 1;
						min_altitude = cells[j][k - 1].altitude;
					}
				}

				//east
				if (k < w - 1) {
					if (cells[j][k + 1].altitude < min_altitude) {
						next_row = j;
						next_column = k + 1;
						min_altitude = cells[j][k + 1].altitude;
					}
				}

				//south
				if (j < h - 1) {
					if (cells[j + 1][k].altitude < min_altitude) {
						next_row = j + 1;
						next_column = k;
						min_altitude = cells[j + 1][k].altitude;
					}
				}
				if (next_row >= 0 && next_column >= 0) {
					cells[next_row][next_column].prev_row
						[cells[next_row][next_column].prev_count] = j;
					cells[next_row][next_column].prev_column
						[cells[next_row][next_column].prev_count] = k;
					cells[next_row][next_column].prev_count++;
					cells[j][k].have_next = 1;
				}
			}
		}
		
		queue_index = 0;
		for (j = 0; j < h; j++) {
			for (k = 0; k < w; k++) {
				if (0 == cells[j][k].have_next) {
					cell_queue_start = 0;
					cell_queue_end = 0;

					cell_queue[queue_index].cells[cell_queue_end++] 
							= &cells[j][k];
					cell_queue[queue_index].min = j * w + k;

					for (; cell_queue_start < cell_queue_end; 
							cell_queue_start++) {
						for (l = 0; 
							l < cell_queue[queue_index].cells
								[cell_queue_start]->prev_count; 
							l++) {
							row = cell_queue[queue_index].cells
								[cell_queue_start]->prev_row[l];
							column = cell_queue[queue_index].cells
								[cell_queue_start]->prev_column[l];
							cell_queue[queue_index].cells
								[cell_queue_end++] 
								= &cells[row][column];
							if (row * w + column 
								< cell_queue[queue_index].min) {
								cell_queue[queue_index].min
									= row * w + column;
							}

						}
					}
					cell_queue[queue_index].count = cell_queue_end;

					queue_index++;
					if (queue_index == 26) {
						goto out;
					}
				}

			}
		}

out:
		qsort(cell_queue, queue_index, sizeof(struct queue), compare);

		for (l = 0; l < queue_index; l++) {
			for (j = 0; j < cell_queue[l].count; j++) {
				cell_queue[l].cells[j]->label = 'a' + l;
			}
		}

		printf("Case #%d:\n", i + 1);
		for (j = 0; j < h; j++) {
			for (k = 0; k < w; k++) {
				printf("%c ", cells[j][k].label);
			}
			printf("\n");
		}

	}


err:
	if (fp) {
		fclose(fp);
		fp = NULL;
	}
	return 0;
}
