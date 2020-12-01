package co.edu.javeriana.algoritmos.proyecto.pandemia;

public class Controlador {
	
	static TableroI tablero;
	static Jugador jugador;
	public static void main(String[] args) {
		tablero = new Tablero(10,10,1);
		jugador= new Jugador();
		jugador.jugar(tablero);
//		tablero.getTablero();
//		tablero.imprimirTablero();
//		tablero.eliminarCasillas(9, 5, tablero.colorCasilla(9, 5));
//		System.out.println("eliminar casillas------------");
//		tablero.imprimirTablero();
//		//tablero.bajarCasillas();
//		//System.out.println("bajar casillas ------------");
//		//tablero.imprimirTablero();
//		System.out.println("mover casillas izquierda ------------");
//		tablero.moverCasillasIzquierda();
//		
//		tablero.imprimirTablero();
	}
}
