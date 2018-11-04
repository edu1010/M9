import java.io.IOException;
import java.io.*;

public class Ex7RuntimeProcess {
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub

        try {
            String texto;
            Process aEjecutar = Runtime.getRuntime().exec(args[0]);
            BufferedReader reader = new BufferedReader(new InputStreamReader(aEjecutar.getInputStream()));
            System.out.println("Codi executat:");
            while((texto = reader.readLine()) != null){
                System.out.println(texto);
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}