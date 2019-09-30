using System;
using System.Collections.Generic;
using System.Linq;
    class Program
    {
        static void Main(string[] args)
        {
            var As = Console.ReadLine().ToCharArray().ToList();
            var Bs = Console.ReadLine().ToCharArray().ToList();
            var Cs = Console.ReadLine().ToCharArray().ToList();

            var turn = 'a';
            Func<char,List<char>, char> GetCard = (player, hands) =>
            {
                 if (!hands.Any())
                 {
                     Console.WriteLine(char.ToUpper(player));
                     return ' ';
                 }
                 var tmpTurn = hands[0];
                 hands.RemoveAt(0);
                 return tmpTurn;
            };

            while (true)
            {
                if (turn == 'a')
                    turn = GetCard(turn, As);
                else if (turn == 'b')
                    turn = GetCard(turn, Bs);
                else
                    turn = GetCard(turn, Cs);
                if (turn == ' ') break;
            }
        }
    }