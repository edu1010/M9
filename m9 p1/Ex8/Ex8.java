import java.io.IOException;
import java.io.*;
public class Ex8 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String texto;
        try {
            do {
                texto = reader.readLine();
            } while (!texto.equals("*"));
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}
