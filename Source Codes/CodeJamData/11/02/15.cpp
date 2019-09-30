#include <iostream>
#include <vector>

using namespace std;

  const char*pam = "QWERASDF";
  int mp[256];

int code(char *s) { int a=mp[s[0]], b=mp[s[1]]; if (a>0 && b>0) return 10*a+b; else return 0; }

int swp(int n) { return 10*(n%10) + (n/10); }

main()
{
  memset(mp,0,sizeof(mp));
  for(int i=0;pam[i];i++) mp[pam[i]]=i+1;

  int cases; cin >> cases;
  for(int loop=1;loop<=cases;loop++)
  {
    char s[100]; char b[100], nb=0;

    printf("Case #%d: ", loop);
    int c, d, n;
    char C[100], D[100];
    memset(C,0,sizeof(C));
    memset(D,0,sizeof(D));

    cin >> c;
    while(c--) { scanf("%s",s); int q=code(s); C[q]=C[swp(q)]=s[2]; }
    cin >> d;
    while(d--) { scanf("%s",s); int q=code(s); D[q]=D[swp(q)]=1; }

    cin >> n;
    scanf("%s",s);

    for(int i=0;s[i];i++)
    {
 fprintf(stderr, "Pushing %c\n",s[i]);
      b[nb++] = s[i];
      while(nb >= 2)
      {
        bool keep=0;
        int q=code(b+nb-2);
        if (C[q])
        {
          fprintf(stderr, "Combining to %c\n",C[q]);
          nb--; b[nb-1]=C[q]; keep=1;
        }
        else if (mp[b[nb-1]])
        {
          int q2=10*mp[b[nb-1]];
          for(int j=0;j<nb-1;j++) if (D[q2+mp[b[j]]]) { fprintf(stderr, "Opposition!\n"); nb=0; break; }
        }
        if (!keep) break;
      }
    }

    putchar('[');
    if (nb) { putchar(b[0]); for(int i=1;i<nb;i++) printf(", %c",b[i]); }
    puts("]");
  }
}
