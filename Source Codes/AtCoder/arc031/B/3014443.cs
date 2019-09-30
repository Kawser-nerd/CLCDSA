using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
namespace abc104
{
    class Program
    {
        static bool[][] visited = new bool[10][];
        static char[][] a = new char[10][];
        static void dfs(int i, int j)
        {
            visited[i][j] = true;
            if (i < 9 && !visited[i + 1][j] && a[i + 1][j] == 'o') dfs(i + 1, j);
            if (i > 0 && !visited[i - 1][j] && a[i - 1][j] == 'o') dfs(i - 1, j);
            if (j < 9 && !visited[i][j + 1] && a[i][j + 1] == 'o') dfs(i, j + 1);
            if (j > 0 && !visited[i][j - 1] && a[i][j - 1] == 'o') dfs(i, j - 1);
        }
        static void Main(string[] args)
        {
            for (int i = 0; i < 10; i++)
            {
                a[i] = ReadLine().ToCharArray();
            }
            var yn = "NO";
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        visited[k] = new bool[10];
                        for (int l = 0; l < 10; l++)
                        {
                            visited[k][l] = false;
                        }
                    }
                    char tmp = a[i][j];
                    a[i][j] = 'o';
                    int c = 0;
                    for (int k = 0; k < 10; k++)
                    {
                        for (int l = 0; l < 10; l++)
                        {
                            if (!visited[k][l] && a[k][l] == 'o')
                            {
                                dfs(k, l);
                                c++;
                            }
                        }
                    }
                    if (c == 1) yn = "YES";
                    //WriteLine($"{i},{j}:{c}");
                    a[i][j] = tmp;
                }
            }
            WriteLine(yn);
        }
    }
}