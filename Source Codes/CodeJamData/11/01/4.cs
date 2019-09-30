using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BotTrust
{
    class Program
    {
        internal static void Calculate(string fileInput, string fileOutput)
        {
            string[] splitters = new string[1] { " " };
            string[] fileText = File.ReadAllLines(fileInput);
            string[] fileOutputText = new string[fileText.Length - 1];
            int outputLine = 0;
            for (int index = 1; index < fileText.Length; index++)
            {
                int totalTime = CalculateTime(fileText[index]);
                fileOutputText[outputLine] = "Case #" + index.ToString() + ": " + totalTime.ToString();
                outputLine++;
            }
            File.WriteAllLines(fileOutput, fileOutputText, Encoding.ASCII);
        }

        internal static int CalculateTime(string commandString)
        {
            //Orange is 0, Blue is 1
            int time = 0;
            int[] positions = new int[] {1, 1};
            int lastMover = -1;
            int timeSinceLastOtherRobotMoved = 0;
            string[] splitters = new string[1] { " " };
            string[] commands = commandString.Split(splitters, StringSplitOptions.RemoveEmptyEntries);
            for (int index = 1; index < commands.Length; index += 2)
            {
                int whichBot = (commands[index] == "O") ? 0 : 1;
                int goalButton = int.Parse(commands[index + 1]);
                int moveAmount = Math.Abs(goalButton - positions[whichBot]); //How much we need to move
                if (lastMover != whichBot)
                {
                    //We could have moved during the time the last moves took
                    moveAmount -= timeSinceLastOtherRobotMoved;
                    moveAmount = Math.Max(0, moveAmount);
                }
                int timeItTakesThisTime = moveAmount + 1; //take into account button mashing time
                time += timeItTakesThisTime;
                //update saved data
                if (lastMover == whichBot)
                {
                    timeSinceLastOtherRobotMoved += timeItTakesThisTime;
                }
                else
                {
                    timeSinceLastOtherRobotMoved = timeItTakesThisTime;
                }
                lastMover = whichBot;
                positions[whichBot] = goalButton;
            }

            return time;
        }

        static void Main(string[] args)
        {
            Program.Calculate("../../A-large.in", "../../A-large.out");
            System.Console.WriteLine("Dog");
        }
    }
}
