using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;


class Program
{
    static void Main(string[] Args) {
        var lis = new List<string>(ReadLine().Split(' ')).Select(int.Parse).ToList();
        string Result = "";

        //Path1
        /*
        for (int i = 0; i < lis[2] - lis[0]; i++)
            Result += 'L';
        for(int i = 0;i < lis[3] - lis[1];)
        */


        //Path1
        
        int x_diff = lis[2] - lis[0]; //tx - sx
        int y_diff = lis[3] - lis[1]; //ty - sy
        char add_c_x = (x_diff <= 0) ? 'L' : 'R';
        char add_c_y = (y_diff <= 0) ? 'D' : 'U';
        for (int i = 0; i < Math.Abs(x_diff); i++)
            Result += add_c_x;
        for (int i = 0; i < Math.Abs(y_diff); i++)
            Result += add_c_y;

        //Path2
        x_diff = -(lis[2] - lis[0]); //tx - sx
        y_diff = -(lis[3] - lis[1]); //ty - sy
        add_c_x = (x_diff <= 0) ? 'L' : 'R';
        add_c_y = (y_diff <= 0) ? 'D' : 'U';
        for (int i = 0; i < Math.Abs(x_diff); i++)
            Result += add_c_x;
        for (int i = 0; i < Math.Abs(y_diff); i++)
            Result += add_c_y;

        //Path3
        Result += (lis[3] - lis[1] <= 0) ? 'U' : 'D';
        x_diff = lis[2] - lis[0]; //tx - sx
        y_diff = lis[3] - lis[1]; //ty - sy
        add_c_x = (x_diff <= 0) ? 'L' : 'R';
        add_c_y = (y_diff <= 0) ? 'D' : 'U';
        for (int i = 0; i <= Math.Abs(x_diff); i++)
            Result += add_c_x;
        for (int i = 0; i <= Math.Abs(y_diff); i++)
            Result += add_c_y;
        Result += (lis[2] - lis[0] <= 0) ? 'R' : 'L';

        //Path4
        Result += (lis[3] - lis[1] <= 0) ? 'D' : 'U';
        x_diff = -(lis[2] - lis[0]); //tx - sx
        y_diff = -(lis[3] - lis[1]); //ty - sy
        add_c_x = (x_diff <= 0) ? 'L' : 'R';
        add_c_y = (y_diff <= 0) ? 'D' : 'U';
        for (int i = 0; i <= Math.Abs(x_diff); i++)
            Result += add_c_x;
        for (int i = 0; i <= Math.Abs(y_diff); i++)
            Result += add_c_y;
        Result += (lis[2] - lis[0] <= 0) ? 'L' : 'R';
        
        WriteLine(Result);

        ReadLine();
    }
}