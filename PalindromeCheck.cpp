#include <iostream>
#include <stdexcept>
#include "Deque.h"
using namespace std;

void palindrome_check(string input)
{
    bool skip_letter = false;
    char non_letters[] = {
        ' ', ',', '.', '!', '?', ';', ':', '-', '(', ')', '[', ']', '{', '}', '\''};
    Deque<char> forwards_deque;
    Deque<char> backwards_deque;
    for (int i = 0; i < input.length(); i++)
    {
        skip_letter = false;
        for (int j = 0; j < sizeof(non_letters); j++)
        {
            if (input[i] == non_letters[j])
            {
                skip_letter = true;
                break;
            }
        }
        if (!skip_letter)
        {
            forwards_deque.enqueue_to_back(tolower(input[i]));
            backwards_deque.enqueue_to_front(tolower(input[i]));
        }
    }

    for (int i = 0; i < forwards_deque.size(); i++)
    {
        if (forwards_deque.is_empty() || forwards_deque.size() == 1)
        {
            cout << "'" << input << "' IS a palindrome" << endl;
            return;
        }
        else if (forwards_deque.size() >= 2)
        {
            if (forwards_deque.peek_front() != backwards_deque.peek_front())
            {
                cout << "'" << input << "' IS NOT a palindrome." << endl;
                return;
            }
            else
            {
                forwards_deque.dequeue_from_front();
                forwards_deque.dequeue_from_back();
                backwards_deque.dequeue_from_front();
                backwards_deque.dequeue_from_back();
            }
        }
    }
    cout << "'" << input << "' IS a palindrome" << endl;
}

int main()
{
    // strings with only alphabetical characters
    // correct strings
    palindrome_check("racecar");

    cout << endl;
    palindrome_check("kayak");

    // incorrect strings
    cout << endl;
    palindrome_check("hello");

    cout << endl;
    palindrome_check("world");

    // strings with non alphabetical characters
    // correct strings
    cout << endl;
    palindrome_check("A man, a plan, a canal, Panama");

    cout << endl;
    palindrome_check("Was it a car or a cat I saw?");

    cout << endl;
    palindrome_check("No 'x' in Nixon");

    cout << endl;
    palindrome_check("Madam, in Eden, I'm Adam");

    cout << endl;
    palindrome_check("Don't nod");

    cout << endl;
    palindrome_check("I did, did I?");

    // incorrect strings
    cout << endl;
    palindrome_check("This is not a palindrome");

    cout << endl;
    palindrome_check("This is also not a palindrome");

    cout << endl;
    palindrome_check("This is not a palindrome either");

    return 0;
}
