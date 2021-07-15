# Othello-Bots
Jogo de console em C, permite jogar o clássico de tabuleiro Othello contra uma pessoa, ou contra Bots de níveis diferentes (implementação do algoritmo Minimax). Desenvolvido em Janeiro de 2021

# Menu do jogo
![image](https://user-images.githubusercontent.com/73000207/125838403-7f48269a-a11f-4a66-9acd-a1933ad3450c.png)

# Controles
No menu: A e D movimentam o cursor, e ENTER seleciona a opção.
No jogo: A e D movimentam a seleção entre as possibilidades, e ENTER seleciona a jogada.

# Salvar jogo
Ao final de uma partida, ela pode ser salva em um arquivo .txt com todas as jogadas.


# Implementação dos Bots
- Nível 1: Joga aleatoriamente.
- Nível 2: Faz a jogada que captura mais peças.
- Nível 3: Faz a jogada que deixa na melhor posição instantaneamente.
- Nível 4: Minimax profundidade 3.
- Nível 5: Minimax profundidade 5.
- Nível 7: Minimax profundidade 7.

# Avaliação da posição
Uma posição do tabuleiro é avaliada fazendo a diferença entre o valor total de peças do Bot e o valor total de peças do oponente. Esse valor é calculado somando-se o valor de cada peça relativo a sua posição, tendo as peças nas bordas e quinas pesos maiores, e peças que dão acesso às bordas e quinas pesos menores.

# Algoritmo Minimax
Esse algoritmo constrói uma árvore com todas as possibilidades de movimentos para cada jogador até a profundidade N, e, supondo que o oponente faça a melhor jogada possível, escolhe o caminho que levará à posição menos pior.
