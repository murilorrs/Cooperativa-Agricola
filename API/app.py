import struct
from flask import Flask, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Habilita CORS para todos os domínios e rotas

def ler_dados_dat(file_path):
    dados = []
    try:
        with open(file_path, 'rb') as file:
            while True:
                try:
                    origem = int.from_bytes(file.read(4), byteorder='little', signed=True)
                    carga = int.from_bytes(file.read(4), byteorder='little', signed=True)
                    mm = int.from_bytes(file.read(4), byteorder='little', signed=True)
                    dd = int.from_bytes(file.read(4), byteorder='little', signed=True)
                    tipo = int.from_bytes(file.read(4), byteorder='little', signed=True)
                    peso = struct.unpack('f', file.read(4))[0]
                    pesoLimpo = struct.unpack('f', file.read(4))[0]
                    percImpurezas = struct.unpack('f', file.read(4))[0]
                    percUmidade = struct.unpack('f', file.read(4))[0]
                    
                    dados.append({
                        'origem': origem,
                        'carga': carga,
                        'MM': mm,
                        'DD': dd,
                        'tipo': tipo,
                        'peso': peso,
                        'pesoLimpo': pesoLimpo,
                        'percImpurezas': percImpurezas,
                        'percUmidade': percUmidade,
                    })
                except struct.error:
                    break 
    except FileNotFoundError:
        print(f"Erro: O arquivo {file_path} não foi encontrado.")
        return []
    except Exception as e:
        print(f"Erro ao ler o arquivo: {e}")
        return []
    return dados

@app.route('/api/dados/', methods=['GET'])
def obter_dados():
    file_path = '../data/database/carregamentos.dat' 
    dados = ler_dados_dat(file_path)
    if not dados:
        return jsonify({"erro": "Nenhum dado encontrado ou erro ao ler o arquivo."}), 404
    return jsonify(dados)

if __name__ == '__main__':
    app.run(debug=True)
