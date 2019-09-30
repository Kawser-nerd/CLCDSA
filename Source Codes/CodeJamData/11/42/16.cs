using System;
using System.IO;
using NUnit.Framework;

namespace DNNX.GoogleCodeJam.Common
{
    public abstract class BaseTest<TTestCase>
    {
        protected abstract Solution<TTestCase> CreateSolution(TextReader input, TextWriter output);

        protected Solution<TTestCase> CreateSolution()
        {
            return CreateSolution(null, null);
        }
        
        protected void SmokeTest(string input, string expectedOutput)
        {
            var inputReader = new StringReader(input.Trim());
            var outputWriter = new StringWriter();
            var solution = CreateSolution(inputReader, outputWriter);
            
            solution.REPL();
           
            var actual = outputWriter.ToString().Trim();
            Assert.AreEqual(expectedOutput.Trim(), actual);            
        }
        
    }
}