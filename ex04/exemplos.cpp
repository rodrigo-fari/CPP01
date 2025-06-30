#include <fstream>
#include <iostream>

int main() {
	{
		//APENAS LEITURA:
		std::ifstream inputFile("entrada.txt");  // Abre o arquivo para leitura
		if (!inputFile.is_open()) {
			std::cerr << "Erro ao abrir o arquivo entrada.txt" << std::endl;
			return 1;
		}
		std::string linha;
		int numeroLinha = 1;
		std::cout << "Conteudo do arquivo:" << std::endl;
		while (std::getline(inputFile, linha)) {
			std::cout << numeroLinha << ": " << linha << std::endl;
			numeroLinha++;
		}
		inputFile.close();  // Fecha o arquivo
		return 0;
	}
	{
		//CRIANDO NOVO ARQUIVO E ESCREVENDO:
		std::ofstream outputFile("saida.txt");  // Cria/abre o arquivo para escrita
		
		if (!outputFile) {
			std::cerr << "Erro ao criar o arquivo saida.txt" << std::endl;
			return 1;
		}
		
		// Escrevendo no arquivo
		outputFile << "Este e um exemplo de arquivo criado pelo programa.\n";
		outputFile << "Segunda linha do arquivo.\n";
		outputFile << "Terceira linha, com numeros: " << 42 << "\n";
		
		outputFile.close();
		std::cout << "Arquivo saida.txt criado com sucesso!" << std::endl;
		
		return 0;
	}
	{
		//MODIFICANDO ARQUIVO EXISTENTE
		// Abre o arquivo em modo append (adiciona ao final)
		std::ofstream file("dados.txt", std::ios::app);
		
		if (!file) {
			std::cerr << "Erro ao abrir o arquivo dados.txt" << std::endl;
			return 1;
		}
		
		file << "\nNovo conteudo adicionado em: " << __DATE__ << " " << __TIME__ << "\n";
		file << "Esta linha foi adicionada pelo programa.\n";
		
		file.close();
		std::cout << "Conteudo adicionado ao arquivo dados.txt" << std::endl;
		
		return 0;
	}
	{
		//CRIANDO ARQUIVO COM CONTEUDO MODIFICADO DO ORIGINAL:
		if (argc != 2) {
			std::cerr << "Uso: " << argv[0] << " <arquivo_entrada>" << std::endl;
			return 1;
		}
		
		// Abre arquivo de entrada
		std::ifstream entrada(argv[1]);
		if (!entrada) {
			std::cerr << "Erro ao abrir o arquivo " << argv[1] << std::endl;
			return 1;
		}
		
		// Cria arquivo de saída
		std::ofstream saida("modificado_" + std::string(argv[1]));
		if (!saida) {
			std::cerr << "Erro ao criar o arquivo de saida" << std::endl;
			entrada.close();
			return 1;
		}
		
		std::string linha;
		int contador = 0;
		
		while (std::getline(entrada, linha)) {
			contador++;
			// Converte para maiúsculas
			for (size_t i = 0; i < linha.size(); ++i) {
				linha[i] = toupper(linha[i]);
			}
			// Adiciona número da linha no início
			saida << contador << ": " << linha << "\n";
		}
		
		entrada.close();
		saida.close();
		
		std::cout << "Arquivo processado. " << contador 
				<< " linhas convertidas para maiusculas e numeradas." << std::endl;
		
		return 0;
	}
	{
		//BUSCA E SUBSTITUICAO EM UM ARQUIVO:
// Função para substituir todas as ocorrências de uma substring
	void substituirTodas(std::string& str, const std::string& busca, const std::string& substitui) {
		size_t pos = 0;
		while ((pos = str.find(busca, pos)) != std::string::npos) {
			str.replace(pos, busca.length(), substitui);
			pos += substitui.length();
	}

		//MAIN()
	std::ifstream entrada("documento.txt");
		std::ofstream saida("documento_modificado.txt");
		
		if (!entrada || !saida) {
			std::cerr << "Erro ao abrir os arquivos" << std::endl;
			return 1;
		}
		
		std::string linha;
		std::string busca = "antiga";
		std::string substitui = "nova";
		int substituicoes = 0;
		
		while (std::getline(entrada, linha)) {
			size_t antes = linha.size();
			substituirTodas(linha, busca, substitui);
			if (linha.size() != antes) {
				substituicoes++;
			}
			saida << linha << "\n";
		}
		
		entrada.close();
		saida.close();
		
		std::cout << "Substituicoes realizadas: " << substituicoes << std::endl;
		
		return 0;
	}
}