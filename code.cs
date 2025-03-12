using System;
using System.Collections.Generic;

class JumbleGame
{
    const int size = 20;
    static string answer;
    static char[] jumble;
    static char[] copy;
    static Queue<char> queue = new Queue<char>();
    static Stack<char> stack = new Stack<char>();
    static int jumblePoint = 0;

    static void Push()
    {
        if (jumblePoint >= jumble.Length)
        {
            Console.WriteLine("No letters remaining in the Jumbled Word");
            return;
        }
        stack.Push(jumble[jumblePoint++]);
    }

    static void Enqueue()
    {
        if (jumblePoint >= jumble.Length)
        {
            Console.WriteLine("No letters remaining in the Jumbled Word");
            return;
        }
        queue.Enqueue(jumble[jumblePoint++]);
    }

    static void QueueToStack()
    {
        if (queue.Count == 0)
        {
            Console.WriteLine("Queue is empty !!");
            return;
        }
        stack.Push(queue.Dequeue());
    }

    static void StackToQueue()
    {
        if (stack.Count == 0)
        {
            Console.WriteLine("No letters in the Stack Word");
            return;
        }
        queue.Enqueue(stack.Pop());
    }

    static void PrintJ()
    {
        for (int i = jumblePoint; i < jumble.Length; i++)
            Console.Write(jumble[i]);
        Console.WriteLine();
    }

    static void PrintS()
    {
        foreach (char c in stack)
            Console.Write(c);
        Console.WriteLine();
    }

    static void PrintQ()
    {
        foreach (char c in queue)
            Console.Write(c);
        Console.WriteLine();
    }

    static bool CheckQueue()
    {
        return new string(queue.ToArray()) == answer;
    }

    static bool CheckStack()
    {
        return new string(stack.ToArray()) == answer;
    }

    static bool Check()
    {
        if (CheckQueue() || CheckStack())
        {
            Console.WriteLine("You Win");
            return true;
        }
        else
        {
            Console.WriteLine("You Lose, Try Again");
            return false;
        }
    }

    static void Main()
    {
        Console.Write("Enter a word: ");
        answer = Console.ReadLine();
        copy = answer.ToCharArray();
        jumble = (char[])copy.Clone();
        Random rnd = new Random();
        jumble = jumble.OrderBy(c => rnd.Next()).ToArray();
        
        bool play = true;
        while (play)
        {
            Console.WriteLine("\nGame Options:");
            Console.WriteLine("1 - Push (From Jumbled Word to Stack)");
            Console.WriteLine("2 - Enqueue (From Jumbled Word to Queue)");
            Console.WriteLine("3 - Pop (From Stack to Queue)");
            Console.WriteLine("4 - Dequeue (From Queue to Stack)");
            Console.WriteLine("5 - Submit the answer");
            Console.WriteLine("6 - Exit");
            Console.Write("\nJumbled Word: "); PrintJ();
            Console.Write("Stack Word: "); PrintS();
            Console.Write("Queue Word: "); PrintQ();
            Console.Write("\nEnter your choice: ");
            int choice = int.Parse(Console.ReadLine());
            
            switch (choice)
            {
                case 1:
                    Push();
                    break;
                case 2:
                    Enqueue();
                    break;
                case 3:
                    StackToQueue();
                    break;
                case 4:
                    QueueToStack();
                    break;
                case 5:
                    if (Check())
                    {
                        Console.WriteLine("Congratulations! You have successfully unscrambled the word.");
                    }
                    play = false;
                    break;
                case 6:
                    play = false;
                    break;
                default:
                    Console.WriteLine("Enter Valid choice");
                    break;
            }
        }
    }
}
