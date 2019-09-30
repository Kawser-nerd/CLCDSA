using System;
using System.Collections.Generic;
using CodeJam;

namespace Problems
{
    public class BotTrust
    {
        private class Step
        {
            public char Bot;
            public int Button;
        }

        public static void Main(string[] args)
        {
            ProblemParser.ParseProblem(@"C:\Users\amissine\Downloads\A-large.in");
            for (var i = 0; i < ProblemParser.Cases; i++)
            {
                var input = ProblemParser.GetNextLine();
                var inputs = input.Split(' ');
                var numberOfSteps = Int32.Parse(inputs[0]);
                var steps = new List<Step>();
                for (int j = 0; j < numberOfSteps; j++)
                {
                    var bot = inputs[1 + j*2][0];
                    var button = Int32.Parse(inputs[2 + j*2]);
                    steps.Add(new Step {Bot = bot, Button = button});
                }

                var bLoc = 1;
                var oLoc = 1;
                var time = 0;
                for (int j = 0; j < numberOfSteps; j++ )
                {
                    var step = steps[j];
                    if (step.Bot == 'B')
                    {
                        var timeTaken = Math.Abs(bLoc - step.Button) + 1;
                        time += timeTaken;
                        bLoc = step.Button;
                        var nextOrangeStep = FindNextStep(j + 1, steps, 'O');
                        if(nextOrangeStep != null) oLoc = MoveTowards(nextOrangeStep.Button, oLoc, timeTaken);
                    }
                    else
                    {
                        var timeTaken = Math.Abs(oLoc - step.Button) + 1;
                        time += timeTaken;
                        oLoc = step.Button;
                        var nextBlueStep = FindNextStep(j + 1, steps, 'B');
                        if (nextBlueStep != null) bLoc = MoveTowards(nextBlueStep.Button, bLoc, timeTaken);
                    }
                }

                ProblemParser.WriteSolution("" + time);
            }
        }

        private static int MoveTowards(int button, int loc, int time)
        {
            if (time >= Math.Abs(button - loc)) return button;
            int mult = button > loc ? 1 : -1;
            return loc + time*mult;
        }

        private static Step FindNextStep(int x, List<Step> steps, char c)
        {
            for(int i = x; i < steps.Count; i++)
            {
                if (steps[i].Bot == c) return steps[i];
            }
            return null;
        }
    }
}
