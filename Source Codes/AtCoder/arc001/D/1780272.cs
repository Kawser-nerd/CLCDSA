using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static bool func(int count,char[][] field)
        {
            if(count==0)
            {
                //?????????
                for (int y = 0; y < 8; y++)
                {
                    Console.WriteLine(new string(field[y].Select(x => x == 'Q' ? 'Q' : '.').ToArray()));
                }
                return true;
            }
            foreach (var pos in getCanSet(field))
            {
                //????????????????
                var clone = field.Select(x => x.ToArray()).ToArray();
                //????????
                set(clone,pos.Item1, pos.Item2);
                //????
                if( func(count - 1, clone) ) return true;
            }
            return false;
        }
        static void set(char[][] field, int y, int x)
        {
            for (int i = 0; i < 8; i++)
            {
                field[y][i] = 'X';
                field[i][x] = 'X';
                if (y + i < 8 && x + i < 8) field[y + i][x + i] = 'X';
                if (y - i >= 0 && x - i >= 0) field[y - i][x - i] = 'X';
                if (y + i < 8 && x - i >= 0) field[y + i][x - i] = 'X';
                if (y - i >= 0 && x + i < 8) field[y - i][x + i] = 'X';
            }
            field[y][x] = 'Q';
        }
        static IEnumerable<Tuple<int, int>> getCanSet(char[][] field)
        {
            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if (field[y][x] == '.') yield return Tuple.Create(y, x);
                }
            }
        }
        static void Main(string[] args)
        {
            var field = Enumerable.Repeat(0, 8).Select(x => Console.ReadLine().ToArray()).ToArray();

            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if (field[y][x] == 'Q')
                    {
                        set(field, y, x);
                    }
                }
            }
            if(field.SelectMany(x=>x).Where(x=>x=='Q').Count()!=3)
            {
                Console.WriteLine("No Answer");
                return;
            }
            //???
            if(func(5, field))return;

            Console.WriteLine("No Answer");
            
        }
    }
}