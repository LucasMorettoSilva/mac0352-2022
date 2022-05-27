#ifndef CLIENT_FUNCTIONALITY_HPP
#define CLIENT_FUNCTIONALITY_HPP

#include <string>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include "util/util.hpp"
#include "util/packages.hpp"
#include "game-board.hpp"

#include<sys/types.h>
#include<signal.h>

#define MAXLINE 4096
#define LISTENQ 1
// true se O jogador está em uma partida.
extern bool user_playing;

// true se O client está logado.
extern bool logged_in;

// pids de processos no client_functionality
extern pid_t *pid_jogo_latencia;
extern pid_t *pid_jogo_ui;
extern pid_t *pid_jogo_pai;

// Contém O nome do jogador com quem se está jogando contra caso se esteja
// jogando contra alguém ou nullptr caso contrário.
extern std::string opponent;

// Cria um novo usuário com nome name e senha password.
void create_user(std::string name, std::string password);

// Caso O usuário name exista e sua senha seja password, loja O usuário no
// servidor e retorna true. Caso contrário, retorna false.
bool user_login(std::string name, std::string password);

// Caso cur_password seja diferente da senha atual, retorna false. Caso seja
// igual, atualiza a senha para new_password.
bool change_password(std::string cur_password, std::string new_password);

// Desloga O usuário do servidor.
void user_logout();

// Mostra todos os usuários conectados ao servidor.
void show_all_connected_users();

// Mostra os n primeiros classificados ou todos se -1.
void show_classifications(int n);

// Retorna uma porta que está livre
int get_free_port();

// Envia um convite para O jogador e retorna O pacote da resposta
// desse jogador
InviteOpponentAckPackage invite_opponent(int sockfd, int uifd);

// Prepara a resposta a um convite e retorna essa resposta
int answer_opponent(std::string recvline);

// Começa a partida após definir quem é O primeiro a jogar e quem será O X.
// A variável tipo é pra saber se é O convidado ou não.
// Retorna a pontuação desse jogador no jogo ou -1 se houve um erro.
int start_match(bool tipo, bool moving_first, bool x, int port, char * ip);

// Envia um movimento na linha row e coluna col.
// row e col devem ser números de 1 a 3. Retorna a pontuação do jogador caso
// O jogo tenha acabado ou -1 caso O jogo não acabou
int send_move(bool x, int connfd);

// Pega O movimento recebido em recvline, atualiza na tabela e checa se
// houve um vencedor. Retorna -1 se O jogo não acabou ou a pontuação do jogador
// caso O jogo tenha acabado
int get_move(bool x, ustring recvline);

// O jogador desiste da partida (perdendo automaticamente).
void surrender(int connfd);

// Envia os resultados da partida para O servidor.
void end_match(int score1, int pipe);

// Ao receber um pingreq, essa função é chamada para enviar um pingback.
void pingback(int pipe);

// Envia um ping para O outro cliente.
void ping_server(int connfd);

// Encerra as operações do cliente (pode ser chamada apenas depois de logout).
void quit(int ui);

#endif /* ifndef CLIENT_FUNCTIONALITY_HPP */
