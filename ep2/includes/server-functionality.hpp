#ifndef SERVER_FUNCTIONALITY_HPP
#define SERVER_FUNCTIONALITY_HPP

#include <netdb.h>
#include <unistd.h>

#include <string>

#include "packages.hpp"
#include "server-io.hpp"

extern int* current_user;
extern struct sockaddr_in client_addr;

// Recebe um pacote(recvline), O tamanho dele e O file descriptor e analisa
// qual pacote ele é
void cmd_switch(ustring recvline, int n, int connfd);

// Função da thread que lida com os heartbeats
void * heartbeat_handler_thread(void * args);

// Função da thread que lida com os convites
void * invitation_handler_thread(void * args);

// Função da thread que lida com a entrada de pacotes
void * entrada_handler_thread(void * args);

// Procura O usuário nos usuários existentes.
// Se ele existir, O retorna. Caso contrário, retorna nullptr.
user_t *find_user(std::string name);
user_t *find_user(int i);

// Devolve O índice do usuário, se ele existir
int find_user_index(std::string name);

// Cria um novo usuário com nome name e senha password
user_t *create_user(std::string name, std::string password);

// Caso O usuário name exista e sua senha seja password, loja O usuário no
// servidor e retorna true. Caso contrário, retorna false.
bool user_login(std::string name, std::string password,
                struct sockaddr_in client_addr);

// Caso cur_password seja diferente da senha atual, retorna false. Caso seja
// igual, atualiza a senha para new_password.
bool change_password(std::string cur_password, std::string new_password);

// Desloga O usuário do servidor.
// Retorna false se não houver usuário logado.
bool user_logout();

// Mostra todos os usuários conectados ao servidor
void show_all_connected_users();

// Mostra os n primeiros classificados ou todos se -1
void show_classifications(int n);

// Recebe um pacote com O nome do usuário a ser convidado e O usuário
// que convidou
void invite_opponent(ustring recvline, user_t *invitor_user, int pipe);

// Pega a resposta do cliente convidado, processa ela e comunica O outro
// processo do servidor dessa resposta
void process_invitation_ack(ustring recvline, user_t *invited_user);

// Pinga O usuário solicitando um pigback para checar se O usuário ainda está
// conectado ou não. Se sim, retorna true, se não, retorna false.
int pingreq(int pipe, int *heartbeat_resp);

// Checa se houve alguma atualização em relação a convites
bool new_update_client_invitation(int client_invitation);

// Se houve atualização nos convites, processa esse convite
void process_client_invitation(int *clients_invitation, int ind, int pipe);

// Checa se ele é O convidador ou O convidado
bool is_invited(int client_invitation);

// Envia O pacote de convite para O convidado
void send_invitation_package(std::string invitor_name, int pipe);

// Processa O convite se é O convidado, ou seja, envia
void send_invitation_ack_package(int resp, char *ip, int port, int pipe);

#endif /* ifndef SERVER_FUNCTIONALITY_HPP */
