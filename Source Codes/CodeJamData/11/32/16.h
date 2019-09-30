#ifndef DOUBLE
  #define FLT float
#else
  #define FLT double
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Function for merge-sorting float point array. */
void merge_sort_f(FLT *a, int n);
/* Function for merge-sorting integer array. */
void merge_sort_i(int *a, int n);

void partition_enum(long *num_partitions_ptr, int **m_j_ptr, \
  int **partition_j_l_ptr, int n, int m, int verbose_flag);

FLT factorial(int n);

FLT num_permu(int n, int k);

void permu_enum(int **v_j_i_ptr, int *num_permu_ptr, int *u_i, int n, int k, \
  int verbose_level);


#ifdef __cplusplus
}
#endif