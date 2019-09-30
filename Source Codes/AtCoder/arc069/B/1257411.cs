//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Text;

public class Test
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        string s = Console.ReadLine();

        var chars = new[] { 'x', 'o' };

        var table_o = new[]{
            0,  // 000
            1,  // 011
            1,  // 101
            0,  // 110
            };
        var table_x = new[]{
            1,  // 001
            0,  // 010
            0,  // 100
            1,  // 111
            };

        char[] str = new char[N];

        for (int j = 0; j < 4; j++)
        {
            int n0 = j % 2;
            int n1 = j / 2;

            bool flag = false;

            for (int i = 0; i < N; i++)
            {
                int m = s[i] == 'o' ? 0 : 1;
                int n2 = n0 ^ n1 ^ m;
                
                str[(i + 1) % N] = n2 == 0 ? 'S' : 'W';

                n0 = n1;
                n1 = n2;
            }
            
            if (n0 == j % 2 && n1 == j / 2) {
                Console.WriteLine(new string(str));
                return;
            }
        }

        Console.WriteLine("-1");
    }
}