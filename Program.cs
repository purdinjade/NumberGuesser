using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace NumberGuesser
{
    class Program
    {
        static void Main(string[] args)
        {
            getAppInfo();

            greetUser();

            
            

            while (true)
            {
                Random random = new Random();
                int correctNumber = random.Next(1, 10);



                int guess = 0;

                //asks user for a number
                Console.WriteLine("Guess a number between 1 and 10");

                //while loop to keep game going til they get number right
                while (guess != correctNumber)
                {
                    string input = Console.ReadLine();

                    //test to make sure input is a number
                    if (!int.TryParse(input, out guess))
                    {
                        PrintColorMessage(ConsoleColor.Red, "Use an actual number");
                        continue;
                    }

                    //actually parses number to int and puts into guess variable
                    guess = Int32.Parse(input);

                    //tests if number is wrong or not.
                    if (guess != correctNumber)
                    {
                        PrintColorMessage(ConsoleColor.Red, "wrong number, try again");
                    }
                }

                PrintColorMessage(ConsoleColor.Yellow, "Correct!");

                Console.WriteLine("Wanna play again? [Y or N]");

                string answer = Console.ReadLine().ToUpper();

                if(answer == "Y"){
                    continue;
                }
                else if (answer == "N")
                {
                    return;
                }
                else
                {
                    return;
                }
            }
        }

        static void getAppInfo()
        {
            string appName = "Number Guesser";
            string appVersion = "1.0.0";
            string appAuthor = "Jade Purdin";

            //changing text to green
            Console.ForegroundColor = ConsoleColor.Green;

            //Writes out app info
            Console.WriteLine(appName + ": " + appVersion + " by " + appAuthor);

            Console.ResetColor();
        }

        static void greetUser()
        {
            Console.WriteLine("What is your name?");

            string inputName = Console.ReadLine();

            Console.WriteLine("Hello, " + inputName);
            Console.WriteLine("I want to play a game...");
        }

        static void PrintColorMessage(ConsoleColor color, string message)
            
        {
            Console.ForegroundColor = color;

            Console.WriteLine(message);

            Console.ResetColor();
        }
    }
}
