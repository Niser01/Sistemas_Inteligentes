import random

class TicTacToe:
    def __init__(self):
        self.board = [' ' for x in range(9)]
        self.player = 'X'

    def display_board(self):
        print(f' {self.board[0]} | {self.board[1]} | {self.board[2]} ')
        print('---+---+---')
        print(f' {self.board[3]} | {self.board[4]} | {self.board[5]} ')
        print('---+---+---')
        print(f' {self.board[6]} | {self.board[7]} | {self.board[8]} ')

    def player_move(self):
        move = int(input(f"Enter your move (1-9): ")) - 1
        if self.board[move] == ' ':
            self.board[move] = self.player
            self.display_board()
        else:
            print("The position is already occupied. Try again.")
            self.player_move()

    def computer_move(self):
        available_moves = [i for i, x in enumerate(self.board) if x == ' ']
        move = random.choice(available_moves)
        self.board[move] = 'O'
        print("The computer moves:")
        self.display_board()

    def winner(self):
        winning_combinations = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # rows
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # columns
            [0, 4, 8], [2, 4, 6]  # diagonals
        ]
        for combination in winning_combinations:
            if self.board[combination[0]] == self.board[combination[1]] == self.board[combination[2]] and self.board[combination[0]] != ' ':
                return self.board[combination[0]]

        return None

    def game_over(self):
        if self.winner() or ' ' not in self.board:
            return True
        return False

    def play(self):
        print("Welcome to Tic Tac Toe!")
        print("You will be playing against the computer.")
        print("You will be X's and the computer will be O's.")

        first_player = input("Would you like to start? (y/n) ")
        while first_player != 'y' and first_player != 'n':
            first_player = input("Invalid input. Would you like to start? (y/n) ")

        self.display_board()
        while not self.game_over():
            if self.winner():
                print(f"{self.winner()} won the game.")
                break
            if first_player == 'y':
                self.player_move()
                first_player = 'n'
            else:
                self.computer_move()
                first_player = 'y'
            if self.winner() == 'X':
                print("You won the game!")
                break
            elif self.winner() == 'O':
                print("The computer won the game.")
                break
        if ' ' not in self.board:
            print("It's a draw!")

game = TicTacToe()
game.play()
