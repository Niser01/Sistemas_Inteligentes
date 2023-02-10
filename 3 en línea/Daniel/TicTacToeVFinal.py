import random

class TicTacToe:
    #Definición inicial del tablero y el símbolo que representa al jugador
    def __init__(self):
        self.board = [' ' for x in range(9)]
        self.player = 'X'

    #Función para imprimir el tablero en consola
    def display_board(self):
        print(f' {self.board[0]} | {self.board[1]} | {self.board[2]} ')
        print('---+---+---')
        print(f' {self.board[3]} | {self.board[4]} | {self.board[5]} ')
        print('---+---+---')
        print(f' {self.board[6]} | {self.board[7]} | {self.board[8]} ')

    #Función que le permite al jugador hacer una movida
    def player_move(self):
        move = int(input("Realiza tu movimiento (1-9): ")) - 1
        if self.board[move] == ' ':
            self.board[move] = self.player
            self.display_board()
        else:
            print("La posición ya está ocupada.")
            self.player_move()

    #Función que decide el movimiento de la máquina
    def computer_move(self):
        available_moves = [i for (i, x) in enumerate(self.board) if x == ' ']

        #Hay que cambiar este random por algo más elaborado
        move = random.choice(available_moves)

        self.board[move] = 'O'
        print("El ordenador movió:")
        self.display_board()

    #Ver si ya hay un ganador
    def winner(self):
        winning_combinations = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Filas
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columnas
            [0, 4, 8], [2, 4, 6]  # Diagonales
        ]
        for combination in winning_combinations:
            if self.board[combination[0]] == self.board[combination[1]] == self.board[combination[2]] and self.board[combination[0]] != ' ':
                return self.board[combination[0]]

        return None

    #Fin del juego
    def game_over(self):
        if self.winner() or ' ' not in self.board:
            return True
        return False

    #Función Main de la clase
    def play(self):

        print("Bienvenido al juego")
        print("Tu serás las 'X' y el computador el 'O'")
        first_player = input("¿Deseas ser el primero en jugar? (y/n) ")
        
        while first_player != 'y' and first_player != 'n':
            first_player = input("Simbolo incorrecto, intentalo nuevamente.")

        self.display_board()
        while not self.game_over():
            if first_player == 'y':
                self.player_move()
                first_player = 'n'
            else:
                self.computer_move()
                first_player = 'y'
            if self.winner() == 'X':
                print("¡Ganaste!")
            elif self.winner() == 'O':
                print("El computador te ganó")
            elif ' ' not in self.board:
                print("Empate")

class ComputerPlayer(TicTacToe):
    #Definición inicial de la clase
    def __init__(self):
        self.botPlayer = "O"
        self.humanPlayer = "X"

    def players(self,state):
        #n = len(state)
        x = 0
        o = 0

        for i in range(9):
            if(state[i] == "X"):
                x = x+1
            elif(state[i] == "0"):
                o = o+1

        


game = TicTacToe()
game.play()
