# Test Plan
##  High level test plan
| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       | Display Main Menu |  None | Options to choose operations to be performed|Options to choose operations to be performed|Requirement based |
|  H_02       |Exit the Program when user is done with operations| 8 | Exited |Exited |Requirement based    |


##  Low level test plan

| **Test ID** | **Description**       | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |   
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       | Add a new Contact |  1 | Options to Enter First name, last name, Phone Number, Email id & City|Options to Enter First name, last name, Phone Number, Email id & City|Requirement based |
|  L_02       | Diaplay All Contacts | 2 |To Display all contacts| Displayed all contacts |Requirement based    |
|  L_03       | Search Contact with First Name | 3 |To Display Required contacts| Displayed Required contact |Requirement based    |
|  L_04       | Search Contact with Phone Number | 4 |To Display Required contacts| Displayed Required contact |Requirement based   |
|  L_05       | Search Contact with City | 5 |To Display Required contacts| Displayed Required contact |Requirement based    |
|  L_06       | Search Contact with First name, phone number or City which does not exist | 3/4/5 |Contact Not Found| Contact Not Found |Requirement based    |
|  L_07       | Delete Contact with Specific Phone Number if it exists | 6 |Contact Deleted Succesfully| Contact Deleted Succesfully |Requirement based    |
|  L_08       | Delete Contact with Specific Phone Number if it does not exist | 6 |Contact Does Not exist| Contact Does Not exist |Requirement based    |
|  L_09       | Save Contacts to file | 7 |Contacts saved| Contacts saved |Requirement based    |
