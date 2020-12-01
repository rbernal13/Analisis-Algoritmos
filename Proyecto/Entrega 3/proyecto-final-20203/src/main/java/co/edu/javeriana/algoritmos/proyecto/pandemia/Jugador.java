package co.edu.javeriana.algoritmos.proyecto.pandemia;

import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Jugador implements JugadorI {

	
	
	public Jugador() {
		super();
		// TODO Auto-generated constructor stub
	}

	@Override
	public List<Casilla> jugar(TableroI tablero){
		int contador=0;
		boolean seguirJugando=true;
		List<Casilla> jugadas = new ArrayList<Casilla>();
		List<Integer> principales = new ArrayList<Integer>();
		
		HashMap<Integer, Integer[]> mapa = new HashMap<Integer, Integer[]>();
		tablero.imprimirTablero();
		while(seguirJugando) {
			boolean realizaJugada=false;
			int filas= tablero.getFilas();
			int columnas = tablero.getColumnas();
			for(int i = 0;i<filas && !realizaJugada ;i++) {
				for(int j=columnas-1;j>=0 && !realizaJugada;j--) {
					if(tablero.colorCasilla(i, j)!=0){
						if(!mapa.containsKey(tablero.colorCasilla(i, j))) {
							System.out.println("ingresa al mapa: "+ tablero.colorCasilla(i, j));
							mapa.put(tablero.colorCasilla(i, j), new Integer[] {-1, -1});
							principales.add(tablero.colorCasilla(i, j));
						}
						Casilla casilla= new Casilla(i, j);
						int [] moverX= {-1,0}; 
						int [] moverY= {0,1};
						
						if (mapa.get(tablero.colorCasilla(i, j))[0]==-1) {
							for(int k =0;k<2;k++) {
								int ySig=i+moverY[k];
								int xSig=j+moverX[k];
								boolean a=(xSig)!=-1;
								boolean b=(ySig)!=filas;
								if( a && b) {
									if (tablero.colorCasilla(ySig, xSig)==tablero.colorCasilla(i, j)) {
										if(principales.get(0)==tablero.colorCasilla(i, j)) {
											System.out.println("valor prioritario = "+ principales.get(0));
											System.out.println("realiza jugada");
											System.out.println("fila: "+ casilla.getFila()+" columna: "+ casilla.getColumna());
											System.out.println("color: "+tablero.colorCasilla(i, j) );
											tablero.efectuarJugada(i,j);
											realizaJugada=true;
											tablero.imprimirTablero();
											jugadas.add(casilla);
										}
										else {
											if(tablero.colorCasilla(i,j)!=0) {
												System.out.println("agrega jugada no prioritaria: "+tablero.colorCasilla(i,j));
												mapa.put(tablero.colorCasilla(i,j), new Integer[] {i, j});
											}
										}
									}
								}
							}
						}
					}
				}
			}

			contador++;
			Set<Integer> keys = mapa.keySet();
			for (Iterator l = keys.iterator(); l.hasNext(); ) {
	          int key = (int) l.next();
	          System.out.println("llave "+key+ " coordenadas = "+mapa.get(key)[0]+ " "+ mapa.get(key)[1]);
			}
			System.out.println();
			for(int i=0;i<principales.size();++i) {
				if(!realizaJugada) {
					if(mapa.get(principales.get(i))[0]!=-1 && (tablero.colorCasilla(mapa.get(principales.get(i))[0], mapa.get(principales.get(i))[1])!=0 )) {
						System.out.println("realiza jugada");
		            	System.out.println("el color del arreglo: "+principales.get(i));
						System.out.println("fila: "+ mapa.get(principales.get(i))[0]+" columna: "+ mapa.get(principales.get(i))[1]);
						System.out.println("color: "+tablero.colorCasilla(mapa.get(principales.get(i))[0], mapa.get(principales.get(i))[1]) );
		            	tablero.efectuarJugada(mapa.get(principales.get(i))[0],mapa.get(principales.get(i))[1]);
		            	realizaJugada=true;
		            	tablero.imprimirTablero();
		            	Casilla casilla= new Casilla(mapa.get(principales.get(i))[0],mapa.get(principales.get(i))[1]);
		            	jugadas.add(casilla);
					}
	            	
				}
				mapa.put(principales.get(i),  new Integer[] {-1, -1} );

			}
			if(contador==1000) {
				break;
			}
			if(!realizaJugada) {
				seguirJugando=false;
			}
		}
		return jugadas;
	}

	@Override
	public String identificacionJugador() {
		// TODO Auto-generated method stub
		return null;
	}

}
