using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            //[summary]B - Trained?

            //????????????
            var buttons = ReadLines();

            //????????????????????????
            //??????????"-1"??
            buttons = buttons.ConvertAll(x => x - 1);

            //"???2"????????????????????????
            int count = CountButtonsPushed(buttons);

            Console.WriteLine(count);
        }

        static int CountButtonsPushed(List<int> buttons)
        {

            //??????????????????????????
            int n = buttons.Count;
            var isPushed = Enumerable.Repeat<bool>(false, n).ToArray();

            //???????????"1"
            int index = 0;
            int count = 1;

            while (true)
            {
                int buttonNum = buttons[index];

                if (buttonNum == 1)
                {
                    return count;
                }
                else
                {
                    if (isPushed[index])
                    {
                        return -1;
                    }
                    else
                    {
                        isPushed[index] = true;
                        index = buttonNum;
                        count++;
                    }
                }
            }
        }

        static List<int> ReadLines(int count = 0)
        {
            //[summary]????????????
            var list = new List<int>();

            //???????????????1?????"count"????
            if (count == 0)
            {
                string s = Console.ReadLine().TrimEnd();
                count = int.Parse(s);
            }            

            for (int i = 0; i < count; i++)
            {
                string s= Console.ReadLine().TrimEnd();
                list.Add(int.Parse(s));
            }

            return list;
        }
    }
}