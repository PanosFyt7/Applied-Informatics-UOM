CREATE DATABASE physiotherapp CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
USE Physiotherapp;

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


DELIMITER $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `fill_date_dimension` (IN `startdate` DATE, IN `stopdate` DATE)   BEGIN
    DECLARE currentdate DATE;
    SET currentdate = startdate;
    WHILE currentdate < stopdate DO
        INSERT INTO time_dimension VALUES (
                        YEAR(currentdate)*10000+MONTH(currentdate)*100 + DAY(currentdate),
                        currentdate,
                        YEAR(currentdate),
                        MONTH(currentdate),
                        DAY(currentdate),
                        DATE_FORMAT(currentdate,'%W'),
                        DATE_FORMAT(currentdate,'%M'),
                        NULL);
        SET currentdate = ADDDATE(currentdate,INTERVAL 1 DAY);
    END WHILE;
END$$

DELIMITER ;


-- Δομή πίνακα για τον πίνακα `patient`
--

CREATE TABLE `patient` (
  `id` int(11) NOT NULL,
  `name` varchar(30) NOT NULL,
  `address` varchar(30) NOT NULL,
  `amka` bigint(11) NOT NULL,
  `phonenumber` bigint(15) NOT NULL,
  `email` varchar(40) NOT NULL,
  `creds_id` int(11) UNIQUE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- Δομή πίνακα για τον πίνακα `physiotherapy_centre`
--

CREATE TABLE `physiotherapy_centre` (
  `id` int(11) NOT NULL,
  `phyname` varchar(15) NOT NULL,
  `address` varchar(30) NOT NULL,
  `afm` bigint(9) NOT NULL,
  `creds_id` int(11) UNIQUE NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- Δομή πίνακα για τον πίνακα `provision`
--

CREATE TABLE `provision` (
  `id` int(11) NOT NULL,
  `id_provision` varchar(11) NOT NULL,
  `proname` varchar(30) NOT NULL,
  `prodescription` varchar(400) NOT NULL,
  `cost` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- Δομή πίνακα για τον πίνακα `session`
--

CREATE TABLE `session` (
  `id` int(11) NOT NULL,
  `comments` varchar(400) NOT NULL,
  `appointment_id` int(11) NOT NULL,
  `provision_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- Δομή πίνακα για τον πίνακα `appointment`
--

CREATE TABLE `appointment` (
  `id` int(11) NOT NULL,
  `time` time(6) NOT NULL,
  `date` date NOT NULL,
  `appointment_status` int(1) NOT NULL,
  `patient_id` int(11) NOT NULL,
  `center_id` int(11) NOT NULL
  
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- Δομή πίνακα για τον πίνακα `credentials`
--

CREATE TABLE `credentials` (
  `id` int(11) NOT NULL,
  `username` varchar(30) NOT NULL,
  `password` varchar(30) NOT NULL,
  `id_role` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Γέμισμα δεδομένων του πίνακα `credentials`
--

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES
(1, 'admin', 'admin', 0);


-- Ευρετήρια για πίνακα `patient`
--
ALTER TABLE `patient`
  ADD PRIMARY KEY (`id`);

--
-- Ευρετήρια για πίνακα `physiotherapy_centre`
--
ALTER TABLE `physiotherapy_centre`
  ADD PRIMARY KEY (`id`);

--
-- Ευρετήρια για πίνακα `provision`
--
ALTER TABLE `provision`
  ADD PRIMARY KEY (`id`);

--
-- Ευρετήρια για πίνακα `session`
--
ALTER TABLE `session`
  ADD PRIMARY KEY (`id`);

--
-- Ευρετήρια για πίνακα `appointment`
--
ALTER TABLE `appointment`
  ADD PRIMARY KEY (`id`);

--
-- Ευρετήρια για πίνακα `credentials`
--
ALTER TABLE `credentials`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT για πίνακα `patient`
--
ALTER TABLE `patient`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT για πίνακα `physiotherapy_centre`
--
ALTER TABLE `physiotherapy_centre`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT για πίνακα `provision`
--
ALTER TABLE `provision`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT για πίνακα `session`
--
ALTER TABLE `session`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT για πίνακα `appointment`
--
ALTER TABLE `appointment`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT για πίνακα `credentials`
--
ALTER TABLE `credentials`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
  
--
-- FOREIGN KEY για πίνακα appointment
--
  
ALTER TABLE `appointment`
ADD CONSTRAINT FK_appointment_patient FOREIGN KEY (patient_id)
REFERENCES `patient` (id);

ALTER TABLE `appointment`
ADD CONSTRAINT FK_appointment_physiotherapy_centre FOREIGN KEY (center_id)
REFERENCES `physiotherapy_centre` (id);

ALTER TABLE `physiotherapy_centre`
ADD CONSTRAINT FK_physiotherapy_centre_creds FOREIGN KEY (creds_id)
REFERENCES `credentials` (id); 

ALTER TABLE `patient`
ADD CONSTRAINT FK_patient_creds FOREIGN KEY (creds_id)
REFERENCES `credentials` (id); 

ALTER TABLE `session`
ADD CONSTRAINT FK_session_appointment FOREIGN KEY (appointment_id)
REFERENCES `appointment` (id); 

ALTER TABLE `session`
ADD CONSTRAINT FK_session_provision FOREIGN KEY (provision_id)
REFERENCES `provision` (id); 


INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'physioworld', '123456', '1');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'phymed', '123', '1');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'iasi', 'qwerty', '1');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'chryso', '123', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'gkoulametis', 'qaz', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'fytilis', '123456', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'mpitsaktsis', '123', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'iordanidis', '123', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'tsoukkas', '123', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'taliotis', '123', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'ttofaras', '123', '2');

INSERT INTO `credentials` (`id`, `username`, `password`, `id_role`) VALUES (NULL, 'koualis', '123', '2');




INSERT INTO `physiotherapy_centre`(`phyname`, `address`, `afm`, `creds_id`) VALUES ('PhysioWorld','Venizelou 23','123567489', '2');

INSERT INTO `physiotherapy_centre`(`phyname`, `address`, `afm`, `creds_id`) VALUES ('PhysioMed','Egnatias 104','123890456', '3');

INSERT INTO `physiotherapy_centre`(`phyname`, `address`, `afm`, `creds_id`) VALUES ('PhysioIasi','Lagkada 56','012345678', '4');



INSERT INTO `provision`(`id_provision`, `proname`, `prodescription`, `cost`) VALUES ('ΜΞ001','Αθλητική Μάλαξη','Είδος θεραπευτικού μασάζ που απευθύνεται σε αθλητές','25');

INSERT INTO `provision`(`id_provision`, `proname`, `prodescription`, `cost`) VALUES ('ΜΞ002','Μυοχαλαρωτικό μασάζ','Μασάζ που απευθύνεται σε όλους, ανεξαρτήτως ηλικίας, επαγγέλματος ή άλλης ιδιότητας. Προσφέρεται τόσο για ανακούφιση από τους μυοσκελετικούς πόνους, όσο και για χαλάρωση και αποτοξίνωση','30');

INSERT INTO `provision`(`id_provision`, `proname`, `prodescription`, `cost`) VALUES ('ΜΞ003','Μάλαξη στα πόδια','Θεραπευτικό μασάζ που απευθύνεται συγκεκριμένα σε ποδοσφαιριστές.','30');

INSERT INTO `provision`(`id_provision`, `proname`, `prodescription`, `cost`) VALUES ('ΘΓ001','Ενδυνάμωση Κορμού','Θεραπευτική Γυμναστική που απευθύνεται σε όσους θέλουν έχουν δισκοπάθεια στην ΟΜΣΣ','40');

INSERT INTO `provision`(`id_provision`, `proname`, `prodescription`, `cost`) VALUES ('ΘΓ002','Ενδυνάμωση Αυχένα ','Θεραπευτική Γυμναστική που απευθύνεται σε όσους θέλουν έχουν δισκοπάθεια στην ΑΜΣΣ','40');



INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Τάσος Χρυσοχοΐδης', 'Αριστοτέλους 4', '1010201010','6980000000','iis20138@uom.edu.gr', '5');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Χρήστος Γκουλαμέτης', 'Εγνατία 89', '1010202020','6942224449','iis20117@uom.edu.gr', '6');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Παναγιώτης Φυτιλής', 'Ερμού 16', '1010203030','6931112227','iis21052@uom.edu.gr', '7');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Γιάννης Μπιτσακτσής', 'Τσιμισκή 30','1010204040','6983334445','ics20056@uom.edu.gr' , '8');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Κώστας Ιορδανίδης', 'Βενιζέλου 30','1010205050','6971234567','ics20077@uom.edu.gr' , '9');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Αντώνης Τσούκας', 'Κύπρου 21','1010206060','6901234567','ics21139@uom.edu.gr' , '10');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Γιώργος Ταλιώτης', 'Τσιμισκή 54','1010207070','6982222234','ics21136@uom.edu.gr' , '11');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Αντρέας Ττοφαράς', 'Μητροπόλεως 20','1010208080','69455566778','ics21137@uom.edu.gr' , '12');

INSERT INTO `patient`(`name`, `address`, `amka`, `phonenumber`, `email`, `creds_id`) VALUES ('Στέφανος Κουαλής', 'Σοφοκλέους 21','1010209090','6931234567','ics21135@uom.edu.gr' , '13');




INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '09:00:00.877000', '2023-06-20', '2', '1', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '10:00:00.877000', '2023-06-22', '2', '1', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '10:00:00.877000', '2023-05-26', '3', '4', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '10:00:00.877000', '2023-06-02', '3', '4', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '11:00:00.877000', '2023-06-09', '3', '4', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '10:00:00.920000', '2023-06-12', '1', '4', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '12:00:00.877000', '2023-06-05', '3', '2', '2');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '13:00:00.877000', '2023-06-08', '3', '2', '2');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '13:00:00.877000', '2023-06-12', '1', '2', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '13:00:00.877000', '2023-06-20', '2', '2', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '10:00:00.877000', '2023-06-20', '2', '3', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '12:00:00.877000', '2023-06-20', '2', '5', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '14:00:00.877000', '2023-06-20', '2', '6', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '10:00:00.877000', '2023-06-5', '3', '5', '3');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '11:00:00.877000', '2023-06-12', '1', '5', '1');

INSERT INTO `appointment` (`id`, `time`, `date`, `appointment_status`, `patient_id`, `center_id`) VALUES (NULL, '12:00:00.877000', '2023-06-12', '1', '6', '1');



INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Αθλητική μάλαξη μετά από αγώνα', '3', '1');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Αθλητική μάλαξη μετά από αγώνα', '4', '1');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Αθλητική μάλαξη μετά από αγώνα', '5', '1');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Πιάσημο μετά από αγώνα. Πραγματοποιήθηκε αθλητική μάλαξη με έμφαση στα πόδια', '6', '3');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Αυχενικό. Πραγματοποιήθηκαν ασκήσεις ενδυνάμωσης πέριοχής', '7', '5');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Αυχενικό. Πραγματοποιήθηκαν ασκήσεις ενδυνάμωσης πέριοχής', '8', '5');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Απλά μασάζ χαλάρωσης', '9', '2');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Απλά μασάζ χαλάρωσης', '14', '2');

INSERT INTO `session` (`id`, `comments`, `appointment_id`, `provision_id`) VALUES (NULL, 'Απλά μασάζ χαλάρωσης', '15', '2');

COMMIT;

