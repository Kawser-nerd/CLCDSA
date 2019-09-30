using System;
using System.Collections.Generic;

class B {
    static char Winner(Queue<char>[] cards) {
        var current = 0;
        while (true) {
            if (cards[current].Count == 0) return (char)('A' + current);
            current = cards[current].Dequeue() - 'a';
        }
    }

    public static void Main() {
        var cards = new Queue<char>[3];
        for (int i = 0; i < 3; ++i)
            cards[i] = new Queue<char>(Console.ReadLine());
        Console.WriteLine(Winner(cards));
    }
}