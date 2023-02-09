class TicTacToe:
    def __init__(self):
        self.board = [' '] * 9

    def display_board(self):
        print(f' {self.board[0]} | {self.board[1]} | {self.board[2]} ')
        print('---+---+---')
        print(f' {self.board[3]} | {self.board[4]} | {self.board[5]} ')
        print('---+---+---')
        print(f' {self.board[6]} | {self.board[7]} | {self.board[8]} ')

    def winner(self):
        winning_positions = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # rows
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # columns
            [0, 4, 8], [2, 4, 6]  # diagonals
        ]
        for pos in winning_positions:
            if self.board[pos[0]] == self.board[pos[1]] == self.board[pos[2]] and self.board[pos[0]] != ' ':
                return self.board[pos[0]]
        return None

    def minimax(self, player):
        if self.winner() == 'X':
            return -1
        if self.winner() == 'O':
            return 1
        if ' ' not in self.board:
            return 0

        best_val = None
        for i in range(9):
            if self.board[i] == ' ':
                self.board[i] = player
                val = self.minimax(self.get_other_player(player))
                self.board[i] = ' '
                if player == 'O':
                    if best_val is None or val > best_val:
                        best_val = val
                else:
                    if best_val is None or val < best_val:
                        best_val = val
        return best_val

    def get_other_player(self, player):
        if player == 'X':
            return 'O'
        return 'X'

    def get_best_move(self, player):
        best_val = None
        best_move = None
        for i in range(9):
            if self.board[i] == ' ':
                self.board[i] = player
                val = self.minimax(self.get_other_player(player))
                self.board[i] = ' '
                if player == 'O':
                    if best_val is None or val > best_val:
                        best_val = val
                        best_move = i               
                else:
                    if best_val is None or val < best_val:
                        best_val = val
                        best_move = i
        return best_move

    def play_game(self):
        print("Welcome to Tic Tac Toe!")
        print("You will be playing against the computer.")
        print("You will be X's and the computer will be O's.")
        self.display_board()
        while True:
            player = 'X'
            player_move = int(input("Enter your move (1-9): ")) - 1
            self.board[player_move] = player
            if self.winner() == 'X':
                print("You won!")
                break
            elif self.winner() == 'O':
                print("The computer won!")
                break
            elif ' ' not in self.board:
                print("It's a draw.")
                break

            player = 'O'
            computer_move = self.get_best_move(player)
            self.board[computer_move] = player
            if self.winner() == 'X':
                print("You won!")
                break
            elif self.winner() == 'O':
                print("The computer won!")
                break
            elif ' ' not in self.board:
                print("It's a draw.")
                break

            self.display_board()

game = TicTacToe()
game.play_game()
