// echodialog.h - EchoDialog specification file
#ifndef ECHODIALOG_H
#define ECHODIALOG_H

#include <QDialog>
class QLabel;							// Forward declaration of QLabel class
class QLineEdit;						// Forward declaration of QLineEdit class
const int MAXIMUM_LENGTH = 30;			// Maximum number of characters of input

class EchoDialog : public QDialog
{
	Q_OBJECT							// Required Q_OBJECT macro
	
public:
	EchoDialog();						// Default constructor
	
private:
	QLineEdit* 	userInputLineEditPtr;	// Pointer to user input QLineEdit
	QLineEdit*  echoLineEditPtr;		// Pointer to uneditable, echo QLineEdit
	QLabel*		echoLabelPtr;			// Pointer to echo QLabel;
	
	QPushButton* quitButtonPtr;			// Pointer to quit QPushButton
	QPushButton* clearButtonPtr;		// Pointer to clear QPushButton
};

#endif
