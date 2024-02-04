/*Word pile isc 2015 */
 import java.util.*;
 public class WordPile
 {
    char [] ch;
    int capacity;
    int top;
    public WordPile(int cap)
    {
        capacity=cap;
        top=-1;
        ch=new char[cap]; // stack 
    }
    void pushchar(char v)
    {
        if(top==capacity-1)
        {
            System.out.println("Stack is full");

        }
        else 
        {
            top++;
            ch[top]=v;
        }
    }
    char popchar()
    {
        if(top==-1)
            return '\\';
        else 
        {
            char c=ch[top];
            top --;
            return c;

        }

    }
   
        


public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the capacity of the WordPile: ");
        int capacity = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        WordPile wordPile = new WordPile(capacity);

        while (true) {
            System.out.println("Choose an operation:");
            System.out.println("1. Push character");
            System.out.println("2. Pop character");
            System.out.println("3. Quit");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter the character to push: ");
                    char characterToPush = scanner.nextLine().charAt(0);
                    wordPile.pushchar(characterToPush);
                    break;
                case 2:
                    char poppedChar = wordPile.popchar();
                    if (poppedChar == '\\') {
                        System.out.println("WordPile is empty!");
                    } else {
                        System.out.println("Popped character: " + poppedChar);
                    }
                    break;
                case 3:
                    System.out.println("Exiting...");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
