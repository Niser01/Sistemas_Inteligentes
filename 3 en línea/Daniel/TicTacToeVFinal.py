import math

available_moves = [0,1,2,3,4,5,6,7,8]
who_started = ""
board = [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']
corners = [0,2,6,8]
middles = [1,3,5,7]
center = 4

class TicTacToe:
    #Definición inicial del tablero y el símbolo que representa al jugador
    def __init__(self):
        self.player = 'X'

    #Función para imprimir el tablero en consola
    def display_board(self):
        print(f' {board[0]} | {board[1]} | {board[2]} ')
        print('---+---+---')
        print(f' {board[3]} | {board[4]} | {board[5]} ')
        print('---+---+---')
        print(f' {board[6]} | {board[7]} | {board[8]} ')

    #Función que le permite al jugador hacer una movida
    def player_move(self):
        move = int(input("Realiza tu movimiento (1-9): ")) - 1
        if board[move] == ' ':
            board[move] = self.player
            available_moves.remove(move)
            self.display_board()
        else:
            print("La posición ya está ocupada.")
            self.player_move()

    #Función que decide el movimiento de la máquina
    def computer_move(self):

        #Criterio de decisión
        #if who_started == "O":
        #    move = random.randint(0, len(corners)-1)
        #    corners.remove(move)
        move = self.minimax(board, "O", available_moves)["p"]

        board[move] = 'O'
        available_moves.remove(move)
        print("El ordenador movió:")
        self.display_board()

    #Ver si ya hay un ganador
    def winner(self, temporal_board):
        winning_combinations = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Filas
            [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columnas
            [0, 4, 8], [2, 4, 6]  # Diagonales
        ]
        for combination in winning_combinations:
            if temporal_board[combination[0]] == temporal_board[combination[1]] == temporal_board[combination[2]] and temporal_board[combination[0]] != ' ':
                return temporal_board[combination[0]]

        return None
    
    #Algoritmo minimax
    def minimax(self, board_list, player, temporal_avaible_moves):
        #Position - Score
        if self.winner(board_list) == "X":
            return {"p": None, "s": 1 * (len(temporal_avaible_moves) + 1)}
        elif self.winner(board_list) == "O":
            return {"p": None, "s": -1 * (len(temporal_avaible_moves) + 1)}
        elif ' ' not in board_list:
            return {"p": None, "s": 0}
        else:
            if player == "X":
                best = {"p": -1, "s": -math.inf}
            elif player == "O":
                best = {"p": -1, "s": math.inf}
            
            for move in temporal_avaible_moves:
                new_board = list(board_list)
                new_board[move] = player
                t_a_m = list(temporal_avaible_moves)
                t_a_m.remove(move)
                sim_score = self.minimax(new_board, "O" if player == "X" else "X", t_a_m)
                sim_score["p"] = int(move)

                if player == "X":
                    if (sim_score["s"] > best["s"]) and sim_score["p"] in available_moves:
                        best = sim_score
                else:
                    if (sim_score["s"] < best["s"]) and sim_score["p"] in available_moves:
                        best = sim_score
            
            return best

    #Fin del juego
    def game_over(self):
        if self.winner(board) or ' ' not in board:
            return True
        return False

    #Función Main de la clase
    def play(self):

        print("Bienvenido al juego")
        print("Tu serás las 'X' y el computador el 'O'")
        first_player = input("¿Deseas ser el primero en jugar? (y/n) ")
        
        while first_player != 'y' and first_player != 'n':
            first_player = input("Simbolo incorrecto, intentalo nuevamente.")

        who_started = "X" if first_player=="y" else "O"

        self.display_board()
        while not self.game_over():
            if first_player == 'y':
                self.player_move()
                first_player = 'n'
            else:
                self.computer_move()
                first_player = 'y'
            if self.winner(board) == 'X':
                print("¡Ganaste!")
            elif self.winner(board) == 'O':
                print("El computador te ganó")
            elif ' ' not in board:
                print("Empate")

game = TicTacToe()
game.play()
