# My Mastermind Game

This is a simple command-line implementation of a Mastermind game in C. The game generates a random 4-digit code, and the player has a limited number of attempts to guess the code correctly.

## How to Play

1. The code is a 4-digit number with each digit ranging from 0 to 9.

2. The player needs to guess the code within a limited number of attempts (default: 10).

3. After each guess, the game provides feedback on the correctness of the guess.

   - The number of correctly placed digits is indicated by "Well placed pieces".
   - The number of misplaced digits (digits that are in the code but in the wrong position) is indicated by "Misplaced pieces".

4. The player wins the game if the entire code is correctly guessed within the given attempts.

## Usage

You can run "My Mastermind" with optional command-line arguments:

- `-c <code>`: Provide a custom code instead of generating a random one.
- `-t <attempts>`: Set the number of attempts allowed (default is 10).

### Examples

1. Run "My Mastermind" with the default random code and the default number of attempts (10):

   ```bash
   ./my_mastermind
   ```

2. Run "My Mastermind" with a custom code "1234" and the default number of attempts (10):

   ```bash
   ./my_mastermind -c 1234
   ```

3. Run "My Mastermind" with the default random code and set the number of attempts to 5:

   ```bash
   ./my_mastermind -t 5
   ```

## Constraints

- The code consists of 4 digits (each ranging from 0 to 9).
- The player has to provide numeric guesses only.
- The game will exit if the player enters a non-numeric guess or sends an EOF (Ctrl + D).

Enjoy playing "My Mastermind"! Can you crack the code in the given attempts? 🎲💡
