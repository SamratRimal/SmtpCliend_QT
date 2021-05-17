#include "application.h"
#include "ui_application.h"
#include "lib/Smpt/SmtpMime"
#include <QLabel>
#include <QMessageBox>


//
bool mailSent;
//collabrated with nabin
Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);
}

Application::~Application()
{
    delete ui;
}

void Application::sendMail(){



       QString user         = ui->yourEmail->text();
       QString password     = ui->password->text();
       QString to           = ui->to->text();
       QString subject      = ui->subject->text();
       QString emailText    = ui->message->text();
       QString user_name    = ui->yourName->text();
       QString recipientName   = ui->toName->text();

       // First we need to create an SmtpClient object
       // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

       SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
       // We need to set the username (your email address) and the password
       // for smtp authentification.
       smtp.setUser(user);
       smtp.setPassword(password);


       MimeMessage message;

       message.setSender(new EmailAddress(user, user_name));
       message.addRecipient(new EmailAddress(to, recipientName));
       message.setSubject(subject);

       // Now add some text to the email.
       // First we create a MimeText object.

       MimeText text;

       text.setText(emailText);

       // Now add it to the mail

       message.addPart(&text);


       // Now we can send the mail

       smtp.connectToHost();
       smtp.login();
      if(smtp.sendMail(message)){
           mailSent =true;
      }
      else{
          mailSent = false;
      };
       smtp.quit();


}

void Application::on_pushButton_clicked()
{
    sendMail();
    if(mailSent){
        QMessageBox::information(this,"Ok","mail has been sent");
        foreach(QLineEdit* le,findChildren<QLineEdit*>()) {
            le->clear();
        }
    }
    else
    {
        QMessageBox::critical(this,"Error","mail has not been sent");

    }
}
