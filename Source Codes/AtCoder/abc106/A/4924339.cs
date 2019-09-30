using System;
using System.Collections.Generic;
using System.Linq;

namespace Astar {
    /*class Node {
        Node((int x, int y) _pos, int _status, int _cost, int _h, int _score, Node node) {
            pos = _pos;
            status = _status;
            cost = _cost;
            h = _h;
            score = _score;
            parent = node;
        }
        public (int x, int y) pos;
        public int status;
        public int cost;
        public int h;
        public int score;
        public Node parent;
    }*/

    /*
    class Program
    {
        static Node AddNode(int dx, int dy, int H, int W, int X, Node node, List<List<string>> s) {
            if (node.pos.x + dx < 0 || node.pos.y + dy < 0
                || node.pos.x + dx >= W || node.pos.y + dy >= H) return null;
            int cost;
            int status;
            switch(s[node.pos.y + dy][node.pos.x + dx]) {
                case ".":
                    cost = 1;
                    status = 0;
                    break;
                case "S":
                    cost = 1;
                    status = 1;
                    break;
                case "G":
                    cost = 1;
                    status = 2;
                    break;
                case "#":
                    cost = X;
                    status = 0;
                    break;
            }
            Node result = new Node((dx, dy), )
        }

        void Process(string[] args)
        {
            var inputs1 = InputIntValues(3);
            int H, W, T;
            H = inputs1[0];
            W = inputs1[1];
            T = inputs1[2];
            var s = new List<List<string>>();
            for(int y = 0; y < H; y++) {
                s[y] = new List<string>();
                string row = Console.ReadLine();
                for(int x = 0; x < W; x++) {
                    s[y][x] = row.Split()[x];
                }
            }
        }

        static List<int> InputIntValues(int length) {
            string rowInput = Console.ReadLine();
            string[] strings = rowInput.Split(' ');
            List<int> returnvalue = new List<int>(length);
            for(int i = 0; i < length; i++) {
                returnvalue[i] = int.Parse(strings[i]);
            }
            return returnvalue;
        }

        static List<List<int>> InputIntMatrix(int X, int Y) {
            var matrix = new List<List<int>>();
            for(int i = 0; i < Y; i++) {
                string row = Console.ReadLine();
                string[] strings = row.Split(' ');
                matrix[i] = new List<int>();
                for (int j = 0; j < X; j++) {
                    matrix[i][j] = int.Parse(strings[j]);
                }
            }
            return matrix;
        }

        static List<List<string>> InputStringMatrix(int X, int Y) {
            var matrix = new List<List<string>>();
            for (int i = 0; i < Y; i++) {
                string row = Console.ReadLine();
                string[] strings = row.Split(' ');
                matrix[i] = new List<string>();
                for (int j = 0; j < X; j++) {
                    matrix[i][j] = strings[j];
                }
            }
            return matrix;
        }
    }*/
}

namespace ProCon {
    class Program {
        static void Main(string[] args) {
            int A, B;
            var tmp = InputIntValues(2);
            A = tmp[0];
            B = tmp[1];
            Console.WriteLine((A - 1) * (B - 1));
        }

        static List<int> InputIntValues(int length) {
            string rowInput = Console.ReadLine();
            string[] strings = rowInput.Split(' ');
            List<int> returnvalue = new List<int>(length);
            for (int i = 0; i < length; i++) {
                returnvalue.Add(int.Parse(strings[i]));
            }
            return returnvalue;
        }

        static List<List<int>> InputIntMatrix(int X, int Y) {
            var matrix = new List<List<int>>();
            for (int i = 0; i < Y; i++) {
                string row = Console.ReadLine();
                string[] strings = row.Split(' ');
                matrix[i] = new List<int>();
                for (int j = 0; j < X; j++) {
                    matrix[i][j] = int.Parse(strings[j]);
                }
            }
            return matrix;
        }

        static List<List<string>> InputStringMatrix(int X, int Y) {
            var matrix = new List<List<string>>();
            for (int i = 0; i < Y; i++) {
                string row = Console.ReadLine();
                string[] strings = row.Split(' ');
                matrix[i] = new List<string>();
                for (int j = 0; j < X; j++) {
                    matrix[i][j] = strings[j];
                }
            }
            return matrix;
        }
    }
}