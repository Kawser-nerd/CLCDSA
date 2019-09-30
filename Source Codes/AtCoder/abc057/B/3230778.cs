using System;
using static System.Console;
using static System.Convert;
class Program
{
    static void Main(string[] args)
    {
        var input = ReadLine().Split(' ');
        var student = ToInt32(input[0]);
        var checkPoint = ToInt32(input[1]);
        var students = new int[student][];
        var checkPoints = new int[checkPoint][];
        for (var i = 0; i < student + checkPoint; i++)
        {
            if (i < student) students[i] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            else checkPoints[i - student] = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        }

        for(var i = 0; i < student; i++)
        {
            var length = GetLength(i, 0,students,checkPoints);
            var point = 1;
            for(var j = 1; j < checkPoint; j++)
            {
                if (length > GetLength(i, j,students,checkPoints)) { length = GetLength(i, j,students,checkPoints);point = j + 1; }
            }
            WriteLine(point);
        }
        
    }

    private static int GetLength(int i,int j,int[][] students,int[][] checkPoints)
    {
        return Math.Abs(students[i][0] - checkPoints[j][0]) + Math.Abs(students[i][1] - checkPoints[j][1]);
    }
}