#ifndef SMTPEXPORTS_H
#define SMTPEXPORTS_H

#ifdef SMTP_BUILD
#define SMTP_EXPORT __declspec(dllimport)
#else
#define SMTP_EXPORT __declspec(dllexport)
#endif

#endif // SMTPEXPORTS_H
