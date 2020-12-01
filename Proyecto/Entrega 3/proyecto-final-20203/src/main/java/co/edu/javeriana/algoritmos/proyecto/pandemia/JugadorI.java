/**
 * 
 */
package co.edu.javeriana.algoritmos.proyecto.pandemia;

import java.util.List;

/**
 * Esta es la interfaz principal que ustedes deberían implementar.  Su implementación DEBE tener una constructora
 * sin parámetros que no lance excepciones.
 * Prohibido modificar, cambiar de paquete o definir en otro paquete.
 */
public interface JugadorI {

    /**
     * Recibe el tablero y retorna la mejor lista de jugadas posible.
     * 
     * @param tablero Tablero para jugar
     * @return Lista de jugadas a realizar en el tablero
     */
    List<Casilla> jugar( TableroI tablero );
    
    
    String identificacionJugador();
    
}
