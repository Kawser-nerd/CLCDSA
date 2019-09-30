using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC093D {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int A = input[0];
            int B = input[1];
            Console.WriteLine("100 100");
            if (A >= B) {
                int blocks = (B - 1) / 2;
                int updans = blocks / 50;
                for (int i = 0; i < updans; i++) {
                    string str = "";
                    string str2 = "";
                    for (int j = 0; j < 50; j++) {
                        str += ".#";
                        str2 += "#.";
                    }
                    Console.WriteLine(str);
                    Console.WriteLine(str2);
                }
                int remblocks = blocks % 50;
                string remstr = "";
                string remstr2 = "";
                for (int i = 0; i < remblocks; i++) {
                    remstr += ".#";
                    remstr2 += "#.";
                }
                int num = 0;
                if (B % 2 == 0) {
                    remstr += "..";
                    remstr2 += ".#";
                    num++;
                }
                for (int i = 0; i < 50 - remblocks - num; i++) {
                    remstr += "..";
                    remstr2 += "..";
                }
                Console.WriteLine(remstr);
                Console.WriteLine(remstr2);
                int remA = 0;
                if (blocks >= 50) {
                    remA = A - (blocks * 2) + 50 - 1;
                } else {
                    remA = A - blocks - 1;
                }
                int downdans = remA / 50;
                int remdans = 50 - updans - 1;
                for (int i = 0; i < remdans - downdans - 1; i++) {
                    string fillstr = "";
                    string fillstr2 = "";
                    for(int j = 0; j < 50; j++) {
                        fillstr += "..";
                        fillstr2 += "..";
                    }
                    Console.WriteLine(fillstr);
                    Console.WriteLine(fillstr2);
                }
                int remdownblock = remA % 50;
                string downfirststr = "";
                string downfirststr2 = "";
                for (int i = 0; i < remdownblock; i++) {
                    downfirststr += "##";
                    downfirststr2 += ".#";
                }
                for (int i = 0; i < 50 - remdownblock; i++) {
                    downfirststr += "##";
                    downfirststr2 += "##";
                }
                Console.WriteLine(downfirststr);
                Console.WriteLine(downfirststr2);
                for(int i = 0; i < downdans; i++) {
                    string downstr = "";
                    string downstr2 = "";
                    for(int j = 0; j < 50; j++) {
                        downstr += "##";
                        downstr2 += ".#";
                    }
                    Console.WriteLine(downstr);
                    Console.WriteLine(downstr2);
                }
            } else {
                int blocks = (A - 1) / 2;
                int updans = blocks / 50;
                for (int i = 0; i < updans; i++) {
                    string str = "";
                    string str2 = "";
                    for (int j = 0; j < 50; j++) {
                        str += "#.";
                        str2 += ".#";
                    }
                    Console.WriteLine(str);
                    Console.WriteLine(str2);
                }
                int remblocks = blocks % 50;
                string remstr = "";
                string remstr2 = "";
                for (int i = 0; i < remblocks; i++) {
                    remstr += "#.";
                    remstr2 += ".#";
                }
                int num = 0;
                if (A % 2 == 0) {
                    remstr += "##";
                    remstr2 += "#.";
                    num++;
                }
                for (int i = 0; i < 50 - remblocks - num; i++) {
                    remstr += "##";
                    remstr2 += "##";
                }
                Console.WriteLine(remstr);
                Console.WriteLine(remstr2);
                int remB = 0;
                if (blocks >= 50) {
                    remB = B - (blocks * 2) + 50 - 1;
                } else {
                    remB = B - blocks - 1;
                }
                int downdans = remB / 50;
                int remdans = 50 - updans - 1;
                for (int i = 0; i < remdans - downdans - 1; i++) {
                    string fillstr = "";
                    string fillstr2 = "";
                    for (int j = 0; j < 50; j++) {
                        fillstr += "##";
                        fillstr2 += "##";
                    }
                    Console.WriteLine(fillstr);
                    Console.WriteLine(fillstr2);
                }
                int remdownblock = remB % 50;
                string downfirststr = "";
                string downfirststr2 = "";
                for (int i = 0; i < remdownblock; i++) {
                    downfirststr += "..";
                    downfirststr2 += "#.";
                }
                for (int i = 0; i < 50 - remdownblock; i++) {
                    downfirststr += "..";
                    downfirststr2 += "..";
                }
                Console.WriteLine(downfirststr);
                Console.WriteLine(downfirststr2);
                for (int i = 0; i < downdans; i++) {
                    string downstr = "";
                    string downstr2 = "";
                    for (int j = 0; j < 50; j++) {
                        downstr += "..";
                        downstr2 += "#.";
                    }
                    Console.WriteLine(downstr);
                    Console.WriteLine(downstr2);
                }
            }
        }
    }
}