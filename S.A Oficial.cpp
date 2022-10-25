 #include <iostream>
#include <locale>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <sstream>

// define para definir o tamanho do vetor
#define Tamnh(vetor,tipo) (sizeof(vetor)/sizeof(tipo))

using namespace std;

void setcolor(unsigned short color){
	
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);	
}

// struct guardando as informações
struct Usuario {
	string nome, email, contato, CPF, nascimento, cod, idade, hito, valor, dia;
}cliente[99], novo;

struct Usu {
	string nome, contato, CNPJ, email, cod;
}fornece[99], nov;

struct Parceiro {
	string cod, nome, contato, CNPJ, email;
}parce[99], novoo;

struct Hardware {
	string cod, nome, fornecedor, valor, descri, vendido;
}hard[99], no;

struct Periferico{
	string cod, nome, fornecedor, valor, descri, vendido;
}peri[99], n;

void inicializar(){
	cliente[1].cod = "1";
    cliente[1].nome = "Emanuel Santos";
    cliente[1].idade = "20";
    cliente[1].CPF = "123.456.789.99";
    cliente[1].contato = "(31) 931204050";
    cliente[1].nascimento ="12/05/1996";
    cliente[1].email ="Emanuelsant@gmail.com";
    cliente[1].hito = "2 Placas mãe";
    cliente[1].dia = "10/04/2015";
    cliente[1].valor = "R$ 640.00";
    
    cliente[2].cod = "2";
    cliente[2].nome = "Paulo Henrique Silva";
    cliente[2].idade = "56";
    cliente[2].CPF = "132.456.897.33";
    cliente[2].contato = "(31) 984142353";
    cliente[2].nascimento = "15/05/1988";
    cliente[2].email = "Paulohenrique@hotmail.com";
    cliente[2].hito = "2 Headset";
    cliente[2].dia = "15/04/2018";
    cliente[2].valor = "R$ 320.00";
    
    cliente[3].cod = "3";
    cliente[3].nome = "Eduardo Gabriel Rodrigues";
    cliente[3].idade = "34";
    cliente[3].CPF = "123.755.873.21";
    cliente[3].contato = "(33) 991273456";
    cliente[3].nascimento = "27/08/1980";
    cliente[3].email = "Edurodrigues@gmail.com";
    cliente[3].hito = "2 WebCam";
    cliente[3].dia = "10/08/2020";
    cliente[3].valor = "R$ 730.00";
    
    cliente[4].cod = "4";
    cliente[4].nome = "Paula Oliveira";
    cliente[4].idade = "19";
    cliente[4].CPF = "321.456.579.77";
    cliente[4].contato = "(51) 984203457";
    cliente[4].nascimento = "21/06/1985";
    cliente[4].email = "Paulaoliver@outlook.com";
    cliente[4].hito = "2 SSD";
    cliente[4].dia = "23/02/2022";
    cliente[4].valor = "R$ 420.00";
    
    fornece[1].cod = "1";
    fornece[1].nome = "Mirão";
    fornece[1].contato = "(11) 2943-2050 / (11) 9 8146-6079";
    fornece[1].email = "atendimento@mirao.com.br";
    fornece[1].CNPJ = "11.181.434/0001-51";
    
    fornece[2].cod = "2";
    fornece[2].nome = "SND";
    fornece[2].contato = "(11) 2187-8400";
    fornece[2].email = "ecommerce@snd.com.br";
    fornece[2].CNPJ = "02.101.894/0001-31";
    
    fornece[3].cod = "3";
    fornece[3].nome = "Fornecedor Mundial";
    fornece[3].contato = "(11) 3825-4749 / (11) 3825-4749";
    fornece[3].email = "vendas@fornecedormundial.com.br";
    fornece[3].CNPJ = "06.697.608/0001-01";
    
    fornece[4].cod = "4";
    fornece[4].nome = "Greg Distribuidora/Informatica";
    fornece[4].contato = "(11) 93282-6439";
    fornece[4].email = "greg@gregdistribuidora.com.br";
    fornece[4].CNPJ = "09.508.861/0001-50";
    
    parce[1].cod = "1";
    parce[1].nome = "Amazon";
    parce[1].contato = "0800 038 0541";
    parce[1].email = "amazonbrazil@gmail.com";
    parce[1].CNPJ = "15.436.940/0001-03";
    
    parce[2].cod = "2";
    parce[2].nome = "Olx";
    parce[2].contato = "(21) 3799 8501";
    parce[2].email = "privacidade@olxbr.com";
    parce[2].CNPJ = "11.818.248/0001-80";
    
    parce[3].cod = "3";
    parce[3].nome = "Mercado livre";
    parce[3].contato = "0800-637-7246";
    parce[3].email = "mlbrazil@gmail.com";
    parce[3].CNPJ = "03.007.331/0001-41";
    
    parce[4].cod = "4";
    parce[4].nome = "Americanas";
    parce[4].contato = "0800-229-4848";
    parce[4].email = "atendimento.acom@americanas.com";
    parce[4].CNPJ = "33.014.556/0001-96";
    
    hard[1].cod = "1";
    hard[1].nome = "Placa Mãe";
    hard[1].descri = "Placa Mãe Para Intel Lga1155 2x Ddr3 6 Usb 2.0 Vga/hdmi Maxxdigital - TG-H61-303-U/P";
    hard[1].fornecedor = "Mirão";
    hard[1].valor = "320.63";
    hard[1].vendido = "3";
    
    hard[2].cod = "2";
    hard[2].nome = "SSD";
    hard[2].descri = "SSD 240GB SSDNOW A400 SATA 3 KINGSTON SA400S37/240G";
    hard[2].fornecedor = "SND";
    hard[2].valor = "209.99";
    hard[2].vendido = "5";
    
    hard[3].cod = "3";
    hard[3].nome = "Adaptadores";
    hard[3].descri = "Cabo Adaptador Extensor Fonte Atx 24 Para 24 Pinos 24cm";
    hard[3].fornecedor = "Fornecedor Mundial";
    hard[3].valor = "53.25";
    hard[3].vendido = "7";
    
    hard[4].cod = "4";
    hard[4].nome = "Gabinete";
    hard[4].descri = "GABINETE 1 BAIA ATX OFFICE CM-03W1 CM03W1RH0010B0X C/FONTE 200W KMEX BOX";
    hard[4].fornecedor = "Greg Distribuidora/Informatica";
    hard[4].valor = "239.50";
    hard[4].vendido = "1";
    
    peri[1].cod = "1";
    peri[1].nome = "Headset Gamer";
    peri[1].descri = "Fone Headset Gamer Usb com Microfone e Led RGB Lehmox - GT-F17";
    peri[1].fornecedor = "Mirão";
    peri[1].valor = "79.74";
    peri[1].vendido = "2";
    
    peri[2].cod = "2";
    peri[2].nome = "WebCam";
    peri[2].descri = "WEBCAM FULL HD C920 - LOGITECH";
    peri[2].fornecedor = "SND";
    peri[2].valor = "364.99";
    peri[2].vendido = "3";
    
    peri[3].cod = "3";
    peri[3].nome = "Amplificador";
    peri[3].descri = "Placa amplificadora para Aparelho de Home";
    peri[3].fornecedor = "Fornecedor Mundial";
    peri[3].valor = "100.00";
    peri[3].vendido = "5";
    
    peri[4].cod = "4";
    peri[4].nome = "Headset";
    peri[4].descri = "FONE DE OUVIDO HEADSET 0591 GAMER RGB USB BRIGHT BOX";
    peri[4].fornecedor = "Greg Distribuidora/Informatica";
    peri[4].valor = "160.00";
    peri[4].vendido = "3";
}

// função para calcular os produtos 
float _stoF(string texto){

    float num = 0;
    istringstream ss(texto);

    if(!(ss >> num)){
        return 0;
    }

    return num;
}

int main(int argc, char** argv) {	
		
	setlocale(LC_ALL, "portuguese");
	
	inicializar();
	
	int x;
    
	int ch;
	
	start:
		
	bool control = true;
	string usuario, senha, menu, novasenha, usuario2;
	int opcao, resposta, y;
	
	// colocar cor no sistema
	system("COLOR 9F");
	
	//aqui vem a data e hora
	time_t now;
    char texto[80];
    time(&now);
    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
    puts(texto);
    
    cout << endl;
	
	// sistema de login
	cout << "  ---------------------------" << endl;
	cout << " |          LOGIN            | "<< endl;
	cout << "  ---------------------------" << endl;
	cout << endl;
	
	cout << " Usuario " << endl;
	cout << " => ";
	system("COLOR 9F");
	cin >> usuario;
	
    cout << endl;
	cout << " Senha " <<endl;
	cout << " => ";
	system("COLOR 9F");
	ch = getch();
	
	// estrutura de repetição para colocar o asterisco na senha
	while (ch != 13 and ch !=8){
		senha.push_back(ch);
		cout << '*';
		ch = getch();
	}
	
	// codição para testar se a senha esta correta
	if (usuario == "GGhardware" && senha == "g145"){
		cout << endl;
	}
	else {
		system("cls");
		cout << " Senha incorreta \n";
		cout << endl;
		goto start;
	}
	
	// loop principal
	while(control) {
	
	system("cls");
		
		system("COLOR 9F");
		
		//aqui vem a data e hora
		time_t now;
	    char texto[80];
	    time(&now);
	    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
	    puts(texto);
		
		setlocale(LC_ALL, "Portuguese");
		
		cout << endl;
		
		// menu principal
		menu = "Menu principal";
		cout<<"      -------------------""\n";
		cout<<"      ¦                 ¦""\n";
		cout<<"      ¦   *BEM VINDO*   ¦""\n";
		cout<<"      ¦                 ¦""\n";
		cout<<"      -------------------""\n",
		cout<<"              | |      (""\n";
		cout<<"           ___|_|___"   "    )"  "\n";
		cout<<"          |_________|  _(_""\n";
		cout<<"                      | ° |" "\n";
		cout<<"                       ---""\n";
		cout << endl;
	
		cout << "   DIGITE UMA OPÇÃO:" << endl;
		cout << endl;
		cout << "   1) CLIENTES" << endl;
		cout << "   2) PRODUTOS" << endl;
		cout << "   3) FORNECEDORES" << endl;
		cout << "   4) PARCEIROS" << endl;
		cout << "   5) AJUDA" << endl;
		cout << "   6) SOBRE" << endl;
		cout << "   0) LOGOUT" << endl;
		cout << endl;
		cout <<	" => ";
		cin >> opcao;
		
		system("cls");
		
		switch (opcao){
			case 1: {
				
				//aqui vem a data e hora
				time_t now;
			    char texto[80];
			    time(&now);
			    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
			    puts(texto);
			    cout << endl;
				
				menu = "Menu cliente";
				while(menu == "Menu cliente"){
					cout << "    ---------------------------" << endl;
					cout << "   |        MENU CLIENTE       |"<< endl;
					cout << "    ---------------------------" << endl;
					cout << endl;
					
					cout << "  1- Visualizar clientes \n";
					cout << "  2- Cadastrar novo cliente \n";
					cout << "  3- Pesquisar cliente \n";
					cout << "  4- Excluir \n";
					cout << "  5- Atualizar dados \n";
					cout << "  6- Voltar ao menu anterior \n";
					cout << endl;
					cout << " => ";
					cin >> opcao;
					system("cls");
					
					switch (opcao){
						
						case 1:{
							
							//aqui vem a data e hora
							time_t now;
						    char texto[80];
						    time(&now);
						    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
						    puts(texto);
							cout << endl;
							
							// menu para visualizar os clientes
							menu = "Menu visualizar";
							while(menu=="Menu visualizar"){
								cout << "  ---------------------------" << endl;
								cout << " |      MENU VISUALIZAR      | "<< endl;
								cout << "  ---------------------------" << endl;
								cout << "\n";
								
								for(int i=0; i<Tamnh(cliente,Usuario); i++){
                    				if( cliente[i].cod!="0" and cliente[i].nome != "" and cliente[i].idade != "0"){
                        			cout<< " Código: " << cliente[i].cod << endl;
                        			cout<< " Nome: " << cliente[i].nome << endl;
                        			cout<< " Idade: " << cliente[i].idade << endl;
									cout<< " CPF: " << cliente[i].CPF << endl;
									cout << " Contato: " << cliente[i].contato << endl;
									cout << " Data de nascimento: " << cliente[i].nascimento << endl;
									cout << " Email: " << cliente[i].email << endl; 
									cout << endl;
									
                    				}
                				}
								
								// loop para voltar aos menus anteriores
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu cliente";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							
							break;
						}
						case 2: {
							menu = "Menu cadastro";
							while(menu=="Menu cadastro"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU CADASTRO       | "<< endl;
								cout << "  ---------------------------" << endl;
								cout << "\n";
								
								// obtendo as novas informações
								int novocod;
								
								cout<<" Informe o cod: ";
								cout << endl;
								cout <<	" => ";
                				cin>>novocod; cin.sync();
                				
                				cout << endl;
                				cout<<" Informe o nome: ";
                				cout << endl;
								cout <<	" => ";
				                getline(cin, novo.nome);
				                
				                cout << endl;
				                cout<<" Informe a idade: ";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, novo.idade);
				                
				                cout << endl;
				                cout << " Informe o CPF: ";
				                cout << endl;
								cout <<	" => ";
								getline(cin, novo.CPF);
								
								cout << endl;
				                cout << " Informe o contato: ";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, novo.contato);
				                
				                cout << endl;
				                cout << " Informe a data de nascimento";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, novo.nascimento);
				                
				                cout << endl;
				                cout << " Informe o email: ";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, novo.email);
				                
								cout << endl;
						        cout << " Informe a Quantidade e o Produto: ";
						        cout << endl;
								cout <<	" => ";
						        getline(cin, novo.hito);

								cout << endl;
						        cout << " Informe o dia: ";
						        cout << endl;
								cout <<	" => ";
						        getline(cin, novo.dia);

								cout << endl;
						        cout << " Informe o valor: ";
						        cout << endl;
								cout <<	" => ";
						        getline(cin, novo.valor);

				                cout << endl;
				                
				                // struct recebendo as novas informações
				                for(int i=0; i<Tamnh(cliente,Usuario); i++){
									if(to_string(novocod) != cliente[i].cod){
										cliente[novocod].cod = to_string(novocod);
										cliente[novocod].nome = novo.nome;
										cliente[novocod].idade = novo.idade;
										cliente[novocod].CPF = novo.CPF;
										cliente[novocod].contato = novo.contato;
										cliente[novocod].nascimento = novo.nascimento;
										cliente[novocod].email = novo.email;
										cliente[novocod].hito = novo.hito;
										cliente[novocod].dia = novo.dia;
										cliente[novocod].valor = novo.valor;
									}
								}
								
								cout << " Cliente cadastrado \n";
								cout << endl;
								
								// loop para voltar aos menus anteriores
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu cliente";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
				                
							 }
						}
						break;
					}
					
						case 3: {
							
							//aqui vem a data e hora
							time_t now;
						    char texto[80];
						    time(&now);
						    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
						    puts(texto);
							cout << endl;
							
							menu = "Menu pesquisar";
							while(menu=="Menu pesquisar"){
								cout << "  ---------------------------" << endl;
								cout << " |       MENU PESQUISAR      |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								// pesquisar o cliente desejado
								cout << " Informe o cod. do cliente: ";
								cout << endl;
								cout <<	" => ";
								cin >> x; 
								cout << "\n";
								
								// fazer o teste e mostrar cliente desejado
								for(int i=0; i<Tamnh(cliente,Usuario); i++){
									if(to_string(x)==cliente[i].cod){
										cout<< " Código: " << cliente[i].cod << endl;
	                        			cout<< " Nome: " << cliente[i].nome << endl;
	                        			cout<< " Idade: " << cliente[i].idade << endl;
										cout<< " CPF: " << cliente[i].CPF << endl;
										cout << " Contato: " << cliente[i].contato << endl;
										cout << " Data de nascimento: " << cliente[i].nascimento << endl;
										cout << " Email: " << cliente[i].email << endl; 
										cout << endl;
										cout << " Histórico de compra: \n";
										cout << " Quantidade e produto: "<< cliente[i].hito << endl << " Dia: " << cliente[i].dia << endl << " Valor: " << cliente[i].valor << endl;
										cout << endl;
									}
								}
								
								if(to_string(x) != cliente[x].cod){
									cout << " Esse código está indisponível \n";
									cout << endl;
								}
								
								// loop para voltar aos menus anteriores
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu cliente";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
								}
								
								break;
							}
							
						case 4:{
							menu = "Menu deletar";
							while(menu=="Menu deletar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
								cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |        MENU DELETAR       |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
							 	cout << " Informe o cod. para excluir o cliente";
								cout << endl;
								cout <<	" => ";
								cin >> x;	
								
								// condição para deletar o cliente
								for(int i=0; i<Tamnh(cliente,Usuario); i++){
									if(to_string(x)==cliente[i].cod){
										cliente[i].cod = "0";
                    					cliente[i].idade = "0";
                    					cliente[i].nome = ""; 
                    					cout << endl;
									}		
								}

								cout << " Cliente deletado \n";
								cout << endl;
								
								// loop para voltar aos menus anteriores
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu cliente";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
							
						case 5:{
							menu = "Menu atualizar";
							while(menu=="Menu atualizar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
								cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU ATUALIZAR      |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " Informe o cod. do cliente que deseja atualizar";
								cout << endl;
								cout <<	" => ";
								cin >> x; cin.sync();
								cout << endl;
								
								// escolher a opção que deseja alterar
								cout << " Informe qual opção você deseja mudar";
								cout << endl;
								cout << " 1- Cod \n";
								cout << " 2- Nome \n";
								cout << " 3- Idade  \n";
								cout << " 4- CPF \n";
								cout << " 5- contato \n";
								cout << " 6- Data de nascimento \n";
								cout << " 7- email \n";
								cout << " 8- Quantidade e Produto \n";
								cout << " 9- Dia da compra \n";
								cout << " 10- Valor da compra \n";
								cout <<	" => ";
								cin >> opcao; cin.sync();
								
								// switch para o struct receber a alteração
								switch (opcao){
									case 1: {
										cout << endl;
										cout<<" Informe o cod: ";
										cout << endl;
										cout <<	" => ";
                						cin>>novo.cod; cin.sync();
                						cliente[x].cod = novo.cod;
										break;
									}
									
									case 2: {
										cout << endl;
		                				cout<<" Informe o nome: ";
		                				cout << endl;
										cout <<	" => ";
						                getline(cin, novo.nome);
						                cliente[x].nome = novo.nome;
										break;
									}
                					
                					case 3: {
		                				cout << endl;
						                cout<<" Informe a idade: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novo.idade);
						                cliente[x].idade = novo.idade;
										break;
									}
									
									case 4: {
										cout << endl;
						                cout << " Informe o CPF: ";
						                cout << endl;
										cout <<	" => ";
										getline(cin, novo.CPF);
										cliente[x].CPF = novo.CPF;
										break;
									}
									
									case 5:{
										cout << endl;
						                cout << " Informe o contato: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novo.contato);
						                cliente[x].contato = novo.contato;
										break;
									}
									
									case 6:{
										cout << endl;
						                cout << " Informe a data de nascimento";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novo.nascimento);
						                cliente[x].nascimento = novo.nascimento;
										break;
									}
									
									case 7:{
										cout << endl;
						                cout << " Informe o email: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novo.email);
						                cliente[x].email = novo.email;
										break;
									}
									
									case 8: {
										cout << endl;
						                cout << " Informe o Produto: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novo.hito);
						                cliente[x].hito = novo.hito;
										break;
									}
									
									case 9: {
										cout << endl;
						                cout << " Informe o dia: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novo.dia);
						                cliente[x].dia = novo.dia;
										break;
									}
									
									case 10:{
										cout << endl;
						                cout << " Informe o valor: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novo.valor);
						                cliente[x].valor = novo.valor;
						                cout << endl; 
										break;
									}
								}
								
								cout << endl;
								cout << " Cliente atualizado \n";
								cout << endl;
								
								// loop para voltar aos menus anteriores
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu cliente";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}	
						
						case 6:{
							menu = "Menu principal";
							break;
						}
					}
				}
				break;
			}
			
			case 2: {
				menu = "Menu produto";
				while (menu == "Menu produto"){
					
					//aqui vem a data e hora
					time_t now;
				    char texto[80];
				    time(&now);
				    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
				    puts(texto);
				    cout << endl;
					
					// menu produto
					
					cout << "  ---------------------------" << endl;
					cout << " |       MENU PRODUTO        |"<< endl;
					cout << "  ---------------------------" << endl;
					cout << endl;
					
					cout << " 1- Perifericos \n";
					cout << " 2- Hardware \n";
					cout << " 3- Voltar menu anterior \n";
					cout << endl;
					cout << " => ";
					cin >> opcao;
					system("cls");
					
					//menu periferico
					switch (opcao){
						case 1: {
							menu = "Menu perifericos";
							while(menu == "Menu perifericos"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |      MENU PERIFÉRICOS     |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
					
								cout << " 1- Visualizar periférico \n";
								cout << " 2- Cadastrar novo periférico \n";
								cout << " 3- Pesquisar periférico \n";
								cout << " 4- Atualizar dados \n";
								cout << " 5- Excluir \n";
								cout << " 6- Voltar ao menu anterior \n";
								cout << " 7- Voltar ao menu principal \n";
								cout << endl;
								cout << " => ";
								cin >> opcao;
								system("cls");
								
								switch (opcao){
									case 1:{
										menu = "Perifericos visualizar";
										while(menu=="Perifericos visualizar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |      MENU VISUALIZAR      | "<< endl;
											cout << "  ---------------------------" << endl;
											cout << "\n";
											
											float total=0;
											
											//mostrar informações
											for(int i=0; i<Tamnh(peri,Periferico); i++){
												if(peri[i].cod!="0" and peri[i].nome!=""){
													cout<< " Código: " << peri[i].cod << endl;
				                        			cout<< " Nome: " << peri[i].nome << endl;
				                        			cout<< " Descrição: " << peri[i].descri << endl;
													cout<< " Fornecedor: " << peri[i].fornecedor << endl;
													cout << " Valor: " << peri[i].valor << endl;
													cout << " Vendidos: " << peri[i].vendido << endl;
													
													// mostrar o total dos perifericos
													total += (_stoF(peri[i].valor)*_stoF(peri[i].vendido));
													cout << endl;
												}
											}

											cout << " O total de vendas é " << total << endl;
											
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu perifericos";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										
										break;
									}
									
									case 2: {
										menu= "Periferico cadastro";
										while(menu=="Periferico cadastro"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |       MENU CADASTRO       | "<< endl;
											cout << "  ---------------------------" << endl;
											cout << "\n";
											
											//recebendo informações do cadastro
											int pericod;
											
											cout<<" Informe o cod: ";
											cout << endl;
											cout <<	" => ";
                							cin>>pericod; cin.sync();
                							
                							cout << endl;
                							cout<<" Informe o nome: ";
                							cout << endl;
											cout <<	" => ";
				                			getline(cin, n.nome);
				                			
				                			cout << endl;
							                cout<<" Informe a descrição: ";
							                cout << endl;
											cout <<	" => ";
							                getline(cin, n.descri);
							                
							                cout << endl;
							                cout << " Informe o fornecedor: ";
							                cout << endl;
											cout <<	" => ";
											getline(cin, n.fornecedor);
											
											cout << endl;
							                cout << " Informe o valor: ";
							                cout << endl;
											cout <<	" => ";
							                getline(cin, n.valor);
							                
							                cout << endl;
				                			cout << " Informe a quantidade vendida: ";
				                			cout << endl;
											cout <<	" => ";
				                			getline(cin, n.vendido);
				                			cout << endl;
				                			
				                			// struct recebendo as novas informações
				                			for(int i=0; i<Tamnh(peri,Periferico); i++){
				                				if(to_string(pericod) != peri[i].cod){
				                					peri[pericod].cod = to_string(pericod);
				                        			peri[pericod].nome = n.nome;
				                        			peri[pericod].descri = n.descri;
													peri[pericod].fornecedor = n.fornecedor;
													peri[pericod].valor = n.valor;
													peri[pericod].vendido = n.vendido;
												}
											}

											cout << " Periférico cadastrado \n";
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu perifericos";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
											
										}
										break;
									}
									
									case 3:{
										menu = "Periferico pesquisar";
										while(menu=="Periferico pesquisar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
											cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |       MENU PESQUISAR      |"<< endl;
											cout << "  ---------------------------" << endl;
											cout << endl;
											
											cout << " Informe o cod. do periférico: ";
											cout << endl;
											cout <<	" => ";
											cin >> x; 
											cout << "\n";
											
											//mostrando informções
											for(int i=0; i<Tamnh(peri,Periferico); i++){
				                				if(to_string(x) == peri[i].cod){
				                					cout<< " Código: " << peri[i].cod << endl;
				                        			cout<< " Nome: " << peri[i].nome << endl;
				                        			cout<< " Descrição: " << peri[i].descri << endl;
													cout<< " Fornecedor: " << peri[i].fornecedor << endl;
													cout << " Valor: " << peri[i].valor << endl;
													cout << " Vendidos: " << peri[i].vendido << endl; 
													cout << endl;
				                				}
				                			}
				                			
				                			if(to_string(x) != peri[x].cod){
												cout << " Esse código está indisponível \n";
												cout << endl;
											}
											
											// loop para voltar aos menus anteriores
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu perifericos";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										break;
									}
									
									case 4:{
										menu = "Periferico atualizar";
										while(menu=="Periferico atualizar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |       MENU ATUALIZAR      |"<< endl;
											cout << "  ---------------------------" << endl;
											cout << endl;
											
											cout << " Informe o cod. do periférico que deseja atualizar";
											cout << endl;
											cout <<	" => ";
											cin >> x; cin.sync();
											cout << endl;
											
											// escolher a opção que deseja atualizar
											cout << " Informe qual opção você deseja mudar";
											cout << endl;
											cout << " 1- Cod \n";
											cout << " 2- Nome \n";
											cout << " 3- Descrição \n";
											cout << " 4- Fornecedor \n";
											cout << " 5- Valor \n";
											cout << " 6- Vendido \n";
											cout <<	" => ";
											cin >> opcao; cin.sync();
											
											// switch para o struct receber as informações
											switch (opcao){
												case 1: {
													cout << endl;
													cout<<" Informe o cod: ";
													cout << endl;
													cout <<	" => ";
			                						cin >> n.cod; cin.sync();
			                						peri[x].cod = n.cod;
													break;
												}
												
												case 2: {
													cout << endl;
					                				cout<<" Informe o nome: ";
					                				cout << endl;
													cout <<	" => ";
									                getline(cin, n.nome);
									                peri[x].nome = n.nome;
													break;
												}
			                					
			                					case 3: {
					                				cout << endl;
									                cout<<" Informe a descrição: ";
									                cout << endl;
													cout <<	" => ";
									                getline(cin, n.descri);
									                peri[x].descri = n.descri;
													break;
												}
												
												case 4: {
													cout << endl;
									                cout << " Informe o fornecedor: ";
									                cout << endl;
													cout <<	" => ";
													getline(cin, n.fornecedor);
													peri[x].fornecedor = n.fornecedor;
													break;
												}
												
												case 5:{
													cout << endl;
									                cout << " Informe o valor: ";
									                cout << endl;
													cout <<	" => ";
									                getline(cin, n.valor);
									                peri[x].valor = n.valor;
													break;
												}
												
												case 6:{
													cout << endl;
									                cout << " Informe o total vendido: ";
									                cout << endl;
													cout <<	" => ";
									                getline(cin, n.vendido);
									                peri[x].vendido = n.vendido;
													break;
												}
											}
											
											cout << endl;
											cout << " Periférico atualizado \n";
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu perifericos";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										break;
									}
									
									case 5:{
										menu = "Periferico deletar";
										while(menu=="Periferico deletar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |        MENU DELETAR       |"<< endl;
											cout << "  ---------------------------" << endl;
											cout << endl;
											
											cout << " Informe o cod. para excluir o periférico";
											cout << endl;
											cout <<	" => ";
											cin >> x;
											
											// condição para deletar
											for(int i=0; i<Tamnh(peri,Periferico); i++){
				                				if(to_string(x) == peri[i].cod){
				                					peri[i].cod = "0"; 
													peri[i].nome = "";
				                				}
				                			}
				                			
				                			cout << endl;
											cout << " Periférico deletado \n";
				                			
				                			// loop para voltar aos menus anteriores
				                			cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu perifericos";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										break;
									}

									case 6:{
										menu = "Menu produto";
										break;
									}
									case 7:{
										menu = "Menu principal";
										break;
									}
								}
							}
							break;
						}
						
						case 2: {
							menu = "Menu hardware";
							while(menu == "Menu hardware"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU HARDWARE       |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " 1- Visualizar hardware \n";
								cout << " 2- Cadastrar novo hardware \n";
								cout << " 3- Pesquisar hardware \n";
								cout << " 4- Atualizar dados \n";
								cout << " 5- Excluir \n";
								cout << " 6- Voltar ao menu anterior \n";
								cout << " 7- Voltar ao menu principal \n";
								cout << endl;
								cout << " => ";
								cin >> opcao;
								system("cls");
								
								switch (opcao){
									case 1:{
										menu = "Hardware vasualizar";
										while(menu == "Hardware vasualizar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |      MENU VISUALIZAR      | "<< endl;
											cout << "  ---------------------------" << endl;
											cout << "\n";
											
											float total=0;
											
											// exibindo as informações
											for(int i=0; i<Tamnh(hard,Hardware); i++){
												if(hard[i].cod!="0" and hard[i].nome!=""){
													cout<< " Código: " << hard[i].cod << endl;
				                        			cout<< " Nome: " << hard[i].nome << endl;
				                        			cout<< " Descrição: " << hard[i].descri << endl;
													cout<< " Fornecedor: " << hard[i].fornecedor << endl;
													cout << " Valor: " << hard[i].valor << endl;
													cout << " Vendidos: " << hard[i].vendido << endl;
													
													//função para mostrar o total do hardware
													total += (_stoF(hard[i].valor)*_stoF(hard[i].vendido));
													cout << endl;
												}
											}
											
											cout << " O total de vendas é " << total << endl;
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu hardware";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										break;
									}
									
									case 2:{
										menu = "Hardware cadastro";
										while(menu == "Hardware cadastro"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
											cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |       MENU CADASTRO       | "<< endl;
											cout << "  ---------------------------" << endl;
											cout << "\n";
											
											int hardcod;
											
											// recebendo informações do cadastro
											cout<<" Informe o cod: ";
											cout << endl;
											cout <<	" => ";
                							cin>>hardcod; cin.sync();
                							
                							cout << endl;
                							cout<<" Informe o nome: ";
                							cout << endl;
											cout <<	" => ";
				                			getline(cin, no.nome);
				                			
				                			cout << endl;
							                cout<<" Informe a descrição: ";
							                cout << endl;
											cout <<	" => ";
							                getline(cin, no.descri);
							                
							                cout << endl;
							                cout << " Informe o fornecedor: ";
							                cout << endl;
											cout <<	" => ";
											getline(cin, no.fornecedor);
											
											cout << endl;
							                cout << " Informe o valor: ";
							                cout << endl;
											cout <<	" => ";
							                getline(cin, no.valor);
							                
							                cout << endl;
				                			cout << " Informe a quantidade vendida: ";
				                			cout << endl;
											cout <<	" => ";
				                			getline(cin, no.vendido);
				                			
				                			// struct recebendo as novas informações
				                			for(int i=0; i<Tamnh(hard,Hardware); i++){
				                				if(to_string(hardcod) != hard[i].cod){
				                					hard[hardcod].cod = to_string(hardcod);
				                        			hard[hardcod].nome = no.nome;
				                        			hard[hardcod].descri = no.descri;
													hard[hardcod].fornecedor = no.fornecedor;
													hard[hardcod].valor = no.valor;
													hard[hardcod].vendido = no.vendido;
												}
											}
											
											cout << endl;
											cout << " Hardware cadastrado \n";
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu hardware";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}	
										}
										break;
									}
									
									case 3:{
										menu = "Hardware pesquisar";
										while(menu == "Hardware pesquisar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |       MENU PESQUISAR      |"<< endl;
											cout << "  ---------------------------" << endl;
											cout << endl;
											
											cout << " Informe o cod. do hardware: ";
											cout << endl;
											cout <<	" => ";
											cin >> x; 
											cout << "\n";
											
											// exibindo informações do do hardware desejado
											for(int i=0; i<Tamnh(hard,Hardware); i++){
												if(to_string(x)==hard[i].cod){
													cout<< " Código: " << hard[i].cod << endl;
				                        			cout<< " Nome: " << hard[i].nome << endl;
				                        			cout<< " Descrição: " << hard[i].descri << endl;
													cout<< " Fornecedor: " << hard[i].fornecedor << endl;
													cout << " Valor: " << hard[i].valor << endl;
													cout << " Vendidos: " << hard[i].vendido << endl; 
													cout << endl;
												}
											}
											
											if(to_string(x)!=hard[x].cod){
												cout << " Esse código não está disponivel \n";
												cout << endl;
											}
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu hardware";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										break;
									}
									
									case 4: {
										menu = "Hardware atualizar";
										while(menu == "Hardware atualizar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |       MENU ATUALIZAR      |"<< endl;
											cout << "  ---------------------------" << endl;
											cout << endl;
											
											cout << " Informe o cod. do hardware que deseja atualizar";
											cout << endl;
											cout <<	" => ";
											cin >> x; cin.sync();
											cout << endl;
											
											cout << " Informe qual opção você deseja mudar";
											cout << endl;
											cout << " 1- Cod \n";
											cout << " 2- Nome \n";
											cout << " 3- Descrição \n";
											cout << " 4- Fornecedor \n";
											cout << " 5- Valor \n";
											cout << " 6- Vendido \n";
											cout <<	" => ";
											cin >> opcao; cin.sync();
											
											// struct recebendo a alteração
											switch (opcao){
												case 1: {
													cout << endl;
													cout<<" Informe o cod: ";
													cout << endl;
													cout <<	" => ";
			                						cin >> no.cod; cin.sync();
			                						hard[x].cod = no.cod;
													break;
												}
												
												case 2: {
													cout << endl;
					                				cout<<" Informe o nome: ";
					                				cout << endl;
													cout <<	" => ";
									                getline(cin, no.nome);
									                hard[x].nome = no.nome;
													break;
												}
			                					
			                					case 3: {
					                				cout << endl;
									                cout<<" Informe a descrição: ";
									                cout << endl;
													cout <<	" => ";
									                getline(cin, no.descri);
									                hard[x].descri = no.descri;
													break;
												}
												
												case 4: {
													cout << endl;
									                cout << " Informe o fornecedor: ";
									                cout << endl;
													cout <<	" => ";
													getline(cin, no.fornecedor);
													hard[x].fornecedor = no.fornecedor;
													break;
												}
												
												case 5:{
													cout << endl;
									                cout << " Informe o valor: ";
									                cout << endl;
													cout <<	" => ";
									                getline(cin, no.valor);
									                hard[x].valor = no.valor;
													break;
												}
												
												case 6:{
													cout << endl;
									                cout << " Informe o total vendido: ";
									                cout << endl;
													cout <<	" => ";
									                getline(cin, no.vendido);
									                hard[x].vendido = no.vendido;
													break;
												}
											}
											
											cout << endl;
											cout << " Hardware atualizado \n";
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu hardware";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										break;
									}
									
									case 5:{
										menu = "Hardware deletar";
										while(menu == "Hardware deletar"){
											
											//aqui vem a data e hora
											time_t now;
										    char texto[80];
										    time(&now);
										    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
										    puts(texto);
										    cout << endl;
											
											cout << "  ---------------------------" << endl;
											cout << " |        MENU DELETAR       |"<< endl;
											cout << "  ---------------------------" << endl;
											cout << endl;
											
											cout << " Informe o cod. para excluir o hardware";
											cout << endl;
											cout <<	" => ";
											cin >> x;
											
											// condição para deletar o hardware
											for(int i=0; i<Tamnh(hard,Hardware); i++) {
                								if(to_string(x)==hard[i].cod){
                								hard[i].cod = "0"; 
												hard[i].nome = "";
                								}
											}
											
											cout << endl;
											cout << " Hardware deletado \n";
											
											// loop para voltar aos menus anteriores
											cout << endl;
											cout << " 0- Voltar ao menu anterior \n";
											cout << " 1- Voltar ao menu principal";
											cout << endl;
											cout <<	" => ";
											cin >> opcao; 
											system("cls");
												switch (opcao){
													case 0: {
														menu = "Menu hardware";
														break;
													}
										
													case 1: {
														menu = "Menu principal";
													break;
													}
												}
										}
										break;
									}
									
									case 6:{
										menu = "Menu produto";
										break;
									}
									case 7:{
										menu = "Menu principal";
										break;
									}
								}
							}
							
							break;
						}
						
						case 3: {
							menu = "Menu principal";
							break;
						}
					}
				}
				break;
			}
			
			case 3:{
				menu = "Menu fornecedor";
				while(menu == "Menu fornecedor"){
					
					//aqui vem a data e hora
					time_t now;
				    char texto[80];
				    time(&now);
				    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
				    puts(texto);
				    cout << endl;
					
					cout << "  ---------------------------" << endl;
					cout << " |     MENU FORNECEDORES     |"<< endl;
					cout << "  ---------------------------" << endl;
					cout << endl;
					
					cout << " 1- Visualizar fornecedores \n";
					cout << " 2- Cadastrar novo fornecedor \n";
					cout << " 3- Pesquisar fornecedor \n";
					cout << " 4- Atualizar dados \n";
					cout << " 5- Excluir \n";
					cout << " 6- Voltar ao menu anterior \n";
					cout << endl;
					cout << " => ";
					cin >> opcao;
					system("cls");
					
					switch (opcao){
						
						case 1:{
							menu = "Fornecedor visualizar";
							while(menu == "Fornecedor visualizar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |      MENU VISUALIZAR      | "<< endl;
								cout << "  ---------------------------" << endl;
								cout << "\n";
								
								// exibir informações
								for(int i = 0; i < Tamnh(fornece,Usu); i++){
									if(fornece[i].cod!="0" and fornece[i].nome != ""){
									cout<< " Código: " << fornece[i].cod << endl;
                        			cout<< " Nome: " << fornece[i].nome << endl;
                        			cout<< " Contato: " << fornece[i].contato << endl;
									cout<< " Email: " << fornece[i].email << endl;
									cout << " CNPJ: " << fornece[i].CNPJ << endl; 
									cout << endl;
									}
								}
								
								// loop para voltar aos menus anteriores
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu fornecedor";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
						
						case 2: {
							menu = "Fornecedor cadastro";
							while(menu == "Fornecedor cadastro"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU CADASTRO       | "<< endl;
								cout << "  ---------------------------" << endl;
								cout << "\n";
								
								// fazendo novo cadastro
								int forneceCod;
								
								cout<<" Informe o cod: ";
								cout << endl;
								cout <<	" => ";
                				cin>>forneceCod; cin.sync();
                				
                				cout << endl;
                				cout<<" Informe o nome: ";
                				cout << endl;
								cout <<	" => ";
				                getline(cin, nov.nome);
				                
				                cout << endl;
				                cout << " Informe o contato: ";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, nov.contato);
				                
				                cout << endl;
				                cout << " Informe o email: ";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, nov.email);
				                
				                cout << endl;
				                cout << " Informe o CNPJ: ";
				                cout << endl;
								cout <<	" => ";
								getline(cin, nov.CNPJ);
								
								// struct recebendo o novo cadastro
								for(int i = 0; i < Tamnh(fornece,Usu); i++){
									if(to_string(forneceCod) != fornece[i].cod){
									fornece[forneceCod].cod = to_string(forneceCod);
									fornece[forneceCod].nome = nov.nome;
									fornece[forneceCod].contato = nov.contato;
									fornece[forneceCod].email = nov.email;
									fornece[forneceCod].CNPJ = nov.CNPJ;
									}
								}
								
								cout << endl;
								cout << " Fornecedor cadastrado \n";
								
								// loop para voltar aos menus anteriores
								cout << endl;
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu fornecedor";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
						
						case 3:{
							menu = "Fornecedor pesquisar";
							while(menu=="Fornecedor pesquisar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
								cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU PESQUISAR      |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " Informe o cod. do fornecedor: ";
								cout << endl;
								cout <<	" => ";
								cin >> x; 
								cout << "\n";
								
								// mostrar as informações do fornecedor desejado
								for(int i=0; i<Tamnh(fornece,Usu); i++) {
                					if(to_string(x)==fornece[i].cod){
                    					cout<< " Código: " << fornece[i].cod << endl;
	                        			cout<< " Nome: " << fornece[i].nome << endl;
										cout << " Contato: " << fornece[i].contato << endl;
										cout << " Email: " << fornece[i].email << endl;
										cout<< " CNPJ: " << fornece[i].CNPJ << endl; 
										cout << endl;
                					}
            					}
            					
            					if(to_string(x) != fornece[x].cod){
									cout << " Esse código está indisponível \n";
									cout << endl;
								}
            					
            					// loop para voltar aos menus anteriores
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu fornecedor";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
						
						case 4:{
							menu = "Fornecedor atualizar";
							while(menu=="Fornecedor atualizar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU ATUALIZAR      |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " Informe o cod. do fornecedor que deseja atualizar";
								cout << endl;
								cout <<	" => ";
								cin >> x; cin.sync();
								cout << endl;
								
								cout << " Informe qual opção você deseja mudar";
								cout << endl;
								cout << " 1- Cod \n";
								cout << " 2- Nome \n";
								cout << " 3- Contato \n";
								cout << " 4- Email \n";
								cout << " 5- CNPJ \n";
								cout <<	" => ";
								cin >> opcao; cin.sync();
								
								// struct recebdo as novas informações
								switch (opcao){
									case 1: {
										cout << endl;
										cout<<" Informe o cod: ";
										cout << endl;
										cout <<	" => ";
                						cin >> nov.cod; cin.sync();
                						fornece[x].cod = nov.cod;
										break;
									}
									
									case 2: {
										cout << endl;
		                				cout<<" Informe o nome: ";
		                				cout << endl;
										cout <<	" => ";
						                getline(cin, nov.nome);
						                fornece[x].nome = nov.nome;
										break;
									}
                					
                					case 3: {
		                				cout << endl;
						                cout<<" Informe o contato: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, nov.contato);
						                fornece[x].contato = nov.contato;
										break;
									}
									
									case 4: {
										cout << endl;
						                cout << " Informe o email: ";
						                cout << endl;
										cout <<	" => ";
										getline(cin, nov.email);
										fornece[x].email = nov.email;
										break;
									}
									
									case 5:{
										cout << endl;
						                cout << " Informe o CNPJ: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, nov.CNPJ);
						                fornece[x].CNPJ = nov.CNPJ;
										break;
									}
								}
								
								cout << endl;
								cout << " Fornecedor atualizado \n";
								
								cout << endl;	
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu fornecedor";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
								
							}
							break;
						}
						
						case 5:{
							menu = "Fornecedor excluir";
							while(menu=="Fornecedor excluir"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |        MENU DELETAR       |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " Informe o cod. para excluir o fornecedor";
								cout << endl;
								cout <<	" => ";
								cin >> x;
								
								// condição para deletar
								for(int i=0; i<Tamnh(fornece,Usu); i++) {
                					if(to_string(x)==fornece[i].cod){
                						fornece[i].cod = "0"; 
										fornece[i].nome = "";
                					}
								}
								
								cout << endl;
								cout << " Fornecedor deletado \n";
								
								// loop para voltar aos menus anteriores
								cout << endl;
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu fornecedor";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
						case 6:{
							menu = "Menu principal";
							break;
						}
					}
				}
				break;
			}
			
			case 4:{
				menu = "Menu parceiro";
				while(menu == "Menu parceiro"){
					
					//aqui vem a data e hora
					time_t now;
				    char texto[80];
				    time(&now);
				    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
				    puts(texto);
				    cout << endl;
					
					cout << "  ---------------------------" << endl;
					cout << " |      MENU PARCEIROS       |"<< endl;
					cout << "  ---------------------------" << endl;
					cout << endl;
					
					cout << " 1- Visualizar parceiros \n";
					cout << " 2- Cadastrar novo parceiro \n";
					cout << " 3- Pesquisar parceiro \n";
					cout << " 4- Atualizar dados \n";
					cout << " 5- Excluir \n";
					cout << " 6- Voltar ao menu anterior \n";
					cout << endl;
					cout << " => ";
					cin >> opcao;
					system("cls");
					
					switch (opcao){
						
						case 1:{
							menu = "Parceiro visualizar";
							while(menu=="Parceiro visualizar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |      MENU VISUALIZAR      | "<< endl;
								cout << "  ---------------------------" << endl;
								cout << "\n";
								
								// exibindo informações
								for(int i = 0; i < Tamnh(parce,Parceiro); i++){
									if(parce[i].cod!="0" and parce[i].nome != ""){
									cout<< " Código: " << parce[i].cod << endl;
                        			cout<< " Nome: " << parce[i].nome << endl;
                        			cout<< " Contato: " << parce[i].contato << endl;
									cout<< " Email: " << parce[i].email << endl;
									cout << " CNPJ: " << parce[i].CNPJ << endl; 
									cout << endl;
									}
								}
								
							// loop para voltar aos menus anteriores
							cout << " 0- Voltar ao menu anterior \n";
							cout << " 1- Voltar ao menu principal";
							cout << endl;
							cout <<	" => ";
							cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu parceiro";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}	
							}
							break;
						}
						
						case 2: {
							menu = "Parceiro cadastro";
							while(menu == "Parceiro cadastro"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU CADASTRO       | "<< endl;
								cout << "  ---------------------------" << endl;
								cout << "\n";
								
								int parcecod;
								
								// recebendo informações do cadastro
								cout<<" Informe o cod: ";
								cout << endl;
								cout <<	" => ";
								cin >> parcecod; cin.sync();
								
								cout << endl;
                				cout<<" Informe o nome: ";
                				cout << endl;
								cout <<	" => ";
								getline(cin, novoo.nome);
								
								cout << endl;
				                cout << " Informe o contato: ";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, novoo.contato);
				                
				                cout << endl;
				                cout << " Informe o email: ";
				                cout << endl;
								cout <<	" => ";
				                getline(cin, novoo.email);
				                
				                cout << endl;
				                cout << " Informe o CNPJ: ";
				                cout << endl;
								cout <<	" => ";
								getline(cin, novoo.CNPJ);
								
								//struct recebendo as informações do cadastro
								for(int i = 0; i < Tamnh(parce,Parceiro); i++){
									if(to_string(parcecod) != parce[i].cod){
									parce[parcecod].cod = to_string(parcecod);
									parce[parcecod].nome = novoo.nome;
									parce[parcecod].contato = novoo.contato;
									parce[parcecod].email = novoo.email;
									parce[parcecod].CNPJ = novoo.CNPJ;
									}	
								}
								
								cout << endl;
								cout << " Parceiro cadastrado \n";
								
								// loop para voltar aos menus anteriores
								cout << endl;
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu parceiro";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
						
						case 3:{
							menu = "Parceiro pesquisar";
							while(menu == "Parceiro pesquisar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
								cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU PESQUISAR      |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " Informe o cod. do parceiro: ";
								cout << endl;
								cout <<	" => ";
								cin >> x; 
								cout << "\n";
								
								// mostrar informações do parceiro desejado
								for(int i = 0; i < Tamnh(parce,Parceiro); i++){
									if(to_string(x) == parce[i].cod){
										cout<< " Código: " << parce[i].cod << endl;
	                        			cout<< " Nome: " << parce[i].nome << endl;
										cout << " Contato: " << parce[i].contato << endl;
										cout << " Email: " << parce[i].email << endl;
										cout<< " CNPJ: " << parce[i].CNPJ << endl; 
										cout << endl;
									}
								}
								
								if(to_string(x) != parce[x].cod){
									cout << " Esse código está indisponível \n";
									cout << endl;
								}
								
								// loop para voltar aos menus anteriores
								cout << endl;
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu parceiro";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
						
						case 4:{
							menu = "Parceiro atualizar";
							while(menu=="Parceiro atualizar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |       MENU ATUALIZAR      |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " Informe o cod. do parceiro que deseja atualizar";
								cout << endl;
								cout <<	" => ";
								cin >> x; cin.sync();
								cout << endl;
								
								cout << " Informe qual opção você deseja mudar";
								cout << endl;
								cout << " 1- Cod \n";
								cout << " 2- Nome \n";
								cout << " 3- Contato \n";
								cout << " 4- Email \n";
								cout << " 5- CNPJ \n";
								cout <<	" => ";
								cin >> opcao; cin.sync();
								
								// struct recebendo a altereção
								switch (opcao){
									case 1: {
										cout << endl;
										cout<<" Informe o cod: ";
										cout << endl;
										cout <<	" => ";
                						cin >> novoo.cod; cin.sync();
                						parce[x].cod = novoo.cod;
										break;
									}
									
									case 2: {
										cout << endl;
		                				cout<<" Informe o nome: ";
		                				cout << endl;
										cout <<	" => ";
						                getline(cin, novoo.nome);
						                parce[x].nome = novoo.nome;
										break;
									}
                					
                					case 3: {
		                				cout << endl;
						                cout<<" Informe o contato: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novoo.contato);
						                parce[x].contato = novoo.contato;
										break;
									}
									
									case 4: {
										cout << endl;
						                cout << " Informe o email: ";
						                cout << endl;
										cout <<	" => ";
										getline(cin, novoo.email);
										parce[x].email = novoo.email;
										break;
									}
									
									case 5:{
										cout << endl;
						                cout << " Informe o CNPJ: ";
						                cout << endl;
										cout <<	" => ";
						                getline(cin, novoo.CNPJ);
						                parce[x].CNPJ = novoo.CNPJ;
										break;
									}
								}
								
								cout << endl;
								cout << " Parceiro atualizado \n";
								
								// loop para voltar aos menus anteriores
								cout << endl;	
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
									switch (opcao){
										case 0: {
											menu = "Menu parceiro";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
								
							}
							break;
						}
						
						case 5:{
							menu = "Parceiro deletar";
							while(menu == "Parceiro deletar"){
								
								//aqui vem a data e hora
								time_t now;
							    char texto[80];
							    time(&now);
							    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
							    puts(texto);
							    cout << endl;
								
								cout << "  ---------------------------" << endl;
								cout << " |        MENU DELETAR       |"<< endl;
								cout << "  ---------------------------" << endl;
								cout << endl;
								
								cout << " Informe o cod. para excluir o parceiro";
								cout << endl;
								cout <<	" => ";
								cin >> x;
								
								// condição para deletar
								for(int i = 0; i < Tamnh(parce,Parceiro); i++){
									if(to_string(x)==parce[i].cod){
										parce[i].cod = "0"; 
										parce[i].nome = "";
									}
								}
								cout << endl;
								cout << " Parceria deletada \n";
								
								cout << endl;
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
								switch (opcao){
										case 0: {
											menu = "Menu parceiro";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
							break;
						}
						
						case 6:{
							menu = "Menu principal";
							break;
						}
					}
				}
				break;
			}
			
			
			case 5:{
				menu = "Menu ajuda";
				while(menu == "Menu ajuda"){
					
					//aqui vem a data e hora
					time_t now;
				    char texto[80];
				    time(&now);
				    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
				    puts(texto);
					cout << endl;
					
					cout << "  ---------------------------" << endl;
					cout << " |        MENU AJUDA         |"<< endl;
					cout << "  ---------------------------" << endl;
					cout << endl;
					
					// perguntas do menu ajuda
					cout << " 1) Onde encontro os clientes. \n";
					cout << " 2) Onde encontro os produtos. \n";
					cout << " 3) Onde encontro os fornecedores. \n";
					cout << " 4) Onde encontro os parceiros \n";
					cout << " 5) Onde encontro informações sobre o sistema. \n";
					cout << " 0) Voltar menu principal \n";
					cout << endl;
					cout <<	" => ";
					cin >> opcao;
					cout << endl;
					
						system("cls");
						cout << "  ---------------------------" << endl;
						cout << " |       MENU RESPOSTA       |"<< endl;
						cout << "  ---------------------------" << endl;
						cout << endl;
						
						// switch para mostrar a resposta
						switch(opcao){
							case 0:{
								menu = "Menu principal";
								break;
							}
							
							case 1: {
								cout << " 1) Onde encontro os clientes. \n";
								cout << endl;
								cout << " No menu Clientes, após entrar com login e senha, escolhendo a opção 1, \n poderá Visualizar, Cadastrar, Pesquisar, Excluir e Atualizar os dados dos clientes. \n";
								break;
							}
							
							case 2: {
								cout << " 2) Onde encontro os produtos. \n";
								cout << endl;
								cout << " No menu Produtos, após entrar com login e senha, escolhendo a opção 2, ao entrar no submenu Produtos, será possível. \n Pesquisar, Cadastrar e Excluir os Hardwares e Periféricos listados. \n";
								break;
							}
							
							case 3:{
								cout << " 3) Onde encontro os fornecedores. \n";
								cout << endl;
								cout << " No menu Fornecedores, após entrar com login e senha, escolhendo a opção 3, \n será possível Visualizar, Cadastrar,Pesquisar, Atualizar e Excluir os fornecedores cadastrados. \n";
								break;
							}
							
							case 4:{
								cout << " 4) Onde encontro os parceiros. \n";
								cout << endl;
								cout << " No menu Parceiros, após entrar com login e senha, escolhendo a opção 4, será possível Visualizar, Cadastrar, Pesquisar, Atualizar e Excluir os parceiros cadastrados. \n";
								break;
							}
							
							case 5:{
								cout << " 5) Onde encontro informações sobre o sistema. \n";
								cout << endl;
								cout << " No menu Sobre, após entrar com login e senha, escolhendo a opção 6, será possível visualizar as informações sobre o sistema, versão e desenvolvedores. \n";
								break;
							}
						}
							if(opcao != 0){
								cout << endl;
								cout << " 0- Voltar ao menu anterior \n";
								cout << " 1- Voltar ao menu principal";
								cout << endl;
								cout <<	" => ";
								cin >> opcao; 
								system("cls");
								switch (opcao){
										case 0: {
											menu = "Menu ajuda";
											break;
										}
										
										case 1: {
											menu = "Menu principal";
											break;
										}
									}
							}
								
				}
			}
			break;
			
			case 6:{
				menu = "Menu sobre";
				while(menu == "Menu sobre"){
					
					//aqui vem a data e hora
					time_t now;
				    char texto[80];
				    time(&now);
				    strftime(texto, sizeof(texto), " Data: %d/%m/%Y \n Hora: %H:%M ", localtime(&now));
				    puts(texto);
				    cout << endl;
					
					cout << "  ---------------------------" << endl;
					cout << " |        MENU SOBRE         |"<< endl;
					cout << "  ---------------------------" << endl;
					cout << endl;
					
					// menu sobre exibindo informações da empresa
					cout << " Versão 21.H2 \n";
					cout << endl;
					cout << " O sistema 21.H2 foi desenvolvido para o gerenciamento interno da loja GGHardware, tendo como funcionalidade informar os fornecedores, \n os produtos, quantidade vendida, dentre outras funções empresarial. \n";
					cout << endl;
					cout << " Esse sistema foi criado por Alexandre, David, Esther, João Pedro. \n";
					cout << endl;
					cout << " Software Solution © 2022 todos os direitos reservados. | CNPJ 16.430.540/0001-05 \n";
				
					cout << endl;
					cout << " Digite 1 para voltar" << endl;
					cout <<	" => "; 
					cin >> opcao;
					menu = "Menu principal";
					system("cls");
					break;
				}
			}
			break;
			
			//case para voltar ao menu do login	
			case 0:{
				cout << " CONTA DESCONECTADA";
				cout << endl;
				cout << endl;
				goto start;
				break;
			}
		}
	}

return 0;
}
