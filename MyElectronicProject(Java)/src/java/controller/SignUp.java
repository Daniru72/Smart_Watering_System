
package controller;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import entity.User;
import java.io.IOException;
import java.util.Date;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import model.HibernateUtil;
import org.hibernate.Criteria;
import org.hibernate.Session;
import org.hibernate.criterion.Restrictions;


@WebServlet(name = "SignUp", urlPatterns = {"/SignUp"})
public class SignUp extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        
        
           Gson gson = new Gson();
        JsonObject responseJson = new JsonObject();
        responseJson.addProperty("success", false);
        
         JsonObject requestJson = gson.fromJson(req.getReader(), JsonObject.class);
       String mobile = requestJson.get("mobile").getAsString();
       String password = requestJson.get("password").getAsString();
       String firstName = requestJson.get("firstName").getAsString();
       String lastName = requestJson.get("lastName").getAsString();
        
      
       
        
        if(mobile.isEmpty()){
          responseJson.addProperty("message", "Please Fill Your Number");
          
        }else if(!mobile.matches("^07[1,2,4,5,6,7,8,0][0-9]{7}$")){
          responseJson.addProperty("message", "Incorrect Your Number");
          
        }else if(firstName.isEmpty()){
           responseJson.addProperty("message", "Please Fill Your First Name");
           
        }else if(lastName.isEmpty()){
           responseJson.addProperty("message", "Please Fill Your Last Name");
           
        }else if(password.isEmpty()){
           responseJson.addProperty("message", "Please Fill Your Password");
           
        }else if(password.length() < 5){
           responseJson.addProperty("message", "Please Fill Your Password");
           
        }else{
        
            Session session = HibernateUtil.getSessionFactory().openSession();
            
            Criteria criteria1 =  session.createCriteria(User.class);
            criteria1.add(Restrictions.eq("mobile", mobile));
            
            if(!criteria1.list().isEmpty()){
               //User already Registered
            
               responseJson.addProperty("message", "Mobile Number Already Used");
               
            }else{
              //New User
            
             User user = new User();;
             user.setFirst_name(firstName);
             user.setLast_name(lastName);
             user.setMobile(mobile);
             user.setPassword(password);
             user.setRegistered_date(new Date());
             
           
            session.save(user);
            session.beginTransaction().commit();
             responseJson.addProperty("success", true);
              responseJson.addProperty("message", "User Registration Success");
            }
            
            session.close();
        
            
        
        }
        
         resp.setContentType("application/json");
         resp.getWriter().write(gson.toJson(responseJson));
        
        
        
        
    }

   
    
}
