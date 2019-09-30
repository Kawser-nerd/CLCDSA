using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;


namespace CodeJam2012
{
    class Problem2
    {
        private const string INPUT = "B-large (1).in";
        private const string OUTPUT = "B-large (1).out";

        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("d:/code/codejam_dotnet/data/" + INPUT);
            var output = new List<string>();
            int counter = 0;
            for (int i = 1; i < input.Length; i += 2)
            {
                output.Add("Case #" + ++counter + ": " + GetResult(input[i], input[i + 1]));
                Console.WriteLine(i + " of " + input.Length);
            }
            File.WriteAllLines("d:/code/codejam_dotnet/data/" + OUTPUT, output);
        }

        private static string GetResult(string input1, string input2)
        {
            string[] split1 = input1.Split();
            long width = Convert.ToInt64(split1[1]);
            long length = Convert.ToInt64(split1[2]);
            
            IList<Student> students = input2.Split().Select((n, i) => new Student(Convert.ToInt32(n), i)).OrderByDescending(n => n.Radius).ToList();

            double currentX = 0;
            double currentY = 0;
            foreach (var student in students)
            {
                double newX = currentX == 0 ? 0 : currentX + student.Radius;
                double newY = currentY;

                if (newX > width)
                {
                    newX = 0;
                    Student last0Student = students.Where(n => n.PositionX == 0).OrderByDescending(n => n.PositionY).First();
                    newY = last0Student.PositionY + (double)last0Student.Radius + student.Radius;
                }

                student.PositionX = newX;
                student.PositionY = newY;

                currentX = newX + student.Radius;
                currentY = newY;
            }

            IList<Student> reorderedStudents = students.OrderBy(n => n.Index).ToList();
            StringBuilder sb = new StringBuilder();
            foreach (var student in reorderedStudents)
            {
                sb.Append(student.PositionX.ToString("0.0"));
                sb.Append(" ");
                sb.Append(student.PositionY.ToString("0.0"));
                sb.Append(" ");
            }

            return sb.ToString().Trim();
        }

        private class Student
        {
            public Student(int radius, int index)
            {
                Radius = radius;
                Index = index;
            }

            public int Radius { get; private set; }
            public int Index { get; private set; }

            public double PositionX { get; set; }
            public double PositionY { get; set; }
        }
    }
}
