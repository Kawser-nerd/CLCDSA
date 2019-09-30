struct {
  int x;
  char *s;
} t[] = {
  {0, "ZERO"},
  {2, "WTO"},
  {8, "GEIHT"},
  {4, "UFOR"},
  {5, "FIVE"},
  {7, "VSEEN"},
  {6, "SIX"},
  {3, "HTREE"},
  {9, "INNE"},
  {1, "ONE"},
};

i,j,v;
main(){
  int n = atoi(gets(&n));
  for(;i++<n;){
    int c[200] = {0};
    int a[10] = {0};
    for(;(v=getchar())!=10;)c[v]++;
    for(j=0;j<10;j++){
      char *p = t[j].s;
      v = a[t[j].x] = c[*p];
      while(*p)c[*p++] -= v;
    }
    printf("Case #%d: ", i);
    for(j=0;j<10;j++){
      for(v=0;v<a[j];v++){
        putchar(48+j);
      }
    }
    puts("");
  }
  return 0;
}

